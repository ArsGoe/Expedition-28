#include "tools/basic_mesh.hpp"
#include "tools/gl_tools.hpp"
#include "tools/vector3d.hpp"
#include <fstream>
#include <iostream>
#include <glbasimac/json.hpp>
#include <filesystem>
#include "rails.hpp"
#include "draw_gare_batiment.hpp"
#include "draw_train.hpp"
#include "texture.hpp"
#include "sol.hpp"

using json = nlohmann::json;


enum Direction{
    HAUT,
    BAS,
    GAUCHE,
    DROITE
};

Direction findDirection(const std::vector<int>& current_pos,const std::vector<int>& ante_pos){
    int dir_x = (current_pos.at(0)) - (ante_pos.at(0));
    int dir_y = (current_pos.at(1)) - (ante_pos.at(1));

    if (dir_x == 0 && dir_y < 0)
    {
        return Direction::BAS;
    }
    else if (dir_x == 0 && dir_y > 0)
    {
        return Direction::HAUT;
    }
    else if (dir_x > 0 && dir_y == 0)
    {
        return Direction::DROITE;
    }
    else{
        return Direction::GAUCHE;
    }
}

void readJsonLoop(std::string file_name){
    std::ifstream file(file_name);

    if (!file.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier\n";
        return ;
    }

    json j = json::parse(file);

    // Positionnement de la grille et des murs
    const auto& size = j["size_grid"];

    drawSol(size);
	drawMur(size);


    // Positionnement des objets sur la grille
    const auto& origin = j["origin"];

    int origin_x = origin[0];
    int origin_y = origin[1];

    myEngine.mvMatrixStack.pushMatrix();
        
		myEngine.mvMatrixStack.addTranslation({ 10.0f*origin_x, 10.0f*origin_y, 0});
        myEngine.mvMatrixStack.addTranslation({ 5.0f, 5.0f, 2.5f });
		myEngine.mvMatrixStack.addHomothety({ 0.4f, 0.4f, 0.6f });
		myEngine.updateMvMatrix();
		drawGare();

	myEngine.mvMatrixStack.popMatrix();

    const auto& train_pos = j["path"][0];

    int train_pos_x = train_pos[0];
    int train_pos_y = train_pos[1];

    myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation({ 10.0f*train_pos_x, 10.0f*train_pos_y, 0});
        myEngine.mvMatrixStack.addTranslation({ 5.0f, 2.5f, 3.f + 2.3*rr });
        myEngine.mvMatrixStack.addHomothety({ 0.4f, 0.4f, 0.4f });
            myEngine.updateMvMatrix();

            drawTrain();

    myEngine.mvMatrixStack.popMatrix();

    for (int i = 0; i < j["path"].size(); i++)
    {
        int x = j["path"][i][0];
        int y = j["path"][i][1];

        int before_x;
        int before_y;

        int after_x;
        int after_y;

        Direction entry_dir;
        Direction exit_dir;

        if (i == 0 || i == j["path"].size() - 1)
        {
            if (i == 0)
            {
                before_x = j["path"][j["path"].size() - 1][0];
                before_y = j["path"][j["path"].size() - 1][1];

                after_x = j["path"][i+1][0];
                after_y = j["path"][i+1][1];
            }
            else
            {
                before_x = j["path"][i-1][0];
                before_y = j["path"][i-1][1];

                after_x = j["path"][0][0];
                after_y = j["path"][0][1];
            }
        }
        else{
            before_x = j["path"][i-1][0];
            before_y = j["path"][i-1][1];

            after_x = j["path"][i+1][0];
            after_y = j["path"][i+1][1];
        }

        if (before_x == after_x)
        {
            myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({ 10.0f*x, 10.0f*y, 0});
			myEngine.updateMvMatrix();

			drawRailDroit();

		    myEngine.mvMatrixStack.popMatrix();
        }
        else if (before_y == after_y)
        {
            myEngine.mvMatrixStack.pushMatrix();
            myEngine.mvMatrixStack.addRotation(M_PI/2, { 0.0f, 0.0f, 1.0f});
            myEngine.mvMatrixStack.addTranslation({ 0.0f, -10.0f, 0.0f});
			myEngine.mvMatrixStack.addTranslation({ 10.0f*y, 10.0f*-x, 0.0f});
            
			myEngine.updateMvMatrix();

			drawRailDroit();

		    myEngine.mvMatrixStack.popMatrix();
        }
        else {
            if (i == 0 || i == j["path"].size() - 1)
            {
                if (i == 0)
                {
                   entry_dir = findDirection(j["path"][i],j["path"][j["path"].size() - 1]);
                   exit_dir = findDirection(j["path"][i+1],j["path"][i]);
                }
                else
                {
                    entry_dir = findDirection(j["path"][i],j["path"][i-1]);
                    exit_dir = findDirection(j["path"][0],j["path"][i]);
                }
            }
            else{
                entry_dir = findDirection(j["path"][i],j["path"][i-1]);
                exit_dir = findDirection(j["path"][i+1],j["path"][i]);
            }

            if ((entry_dir == Direction::HAUT && exit_dir == Direction::DROITE) || (entry_dir == Direction::GAUCHE && exit_dir == Direction::BAS))
            {
                myEngine.mvMatrixStack.pushMatrix();
                    myEngine.mvMatrixStack.addRotation(M_PI/2, { 0.0f, 0.0f, 1.0f});
                    myEngine.mvMatrixStack.addTranslation({ 0.0f, -10.0f, 0.0f});
                    myEngine.mvMatrixStack.addTranslation({ 10.0f*y, 10.0f*-x, 0});
                    myEngine.updateMvMatrix();

                    drawBentRail();

                myEngine.mvMatrixStack.popMatrix();
                myEngine.updateMvMatrix();
            }
            else if ((entry_dir == Direction::GAUCHE && exit_dir == Direction::HAUT) || (entry_dir == Direction::BAS && exit_dir == Direction::DROITE))
            {
                myEngine.mvMatrixStack.pushMatrix();
                    myEngine.mvMatrixStack.addRotation(M_PI, { 0.0f, 0.0f, 1.0f});
                    myEngine.mvMatrixStack.addTranslation({ 0.0f, -10.0f, 0.0f});
                    myEngine.mvMatrixStack.addTranslation({ 10.0f*-x-10, 10.0f*-y, 0});
                    myEngine.updateMvMatrix();

                    drawBentRail();

                myEngine.mvMatrixStack.popMatrix();
                myEngine.updateMvMatrix();
            }
            else if ((entry_dir == Direction::HAUT && exit_dir == Direction::GAUCHE) || (entry_dir == Direction::DROITE && exit_dir == Direction::BAS))
            {
                myEngine.mvMatrixStack.pushMatrix();
                    myEngine.mvMatrixStack.addTranslation({ 10.0f*x, 10.0f*y, 0});
                    myEngine.updateMvMatrix();

                    drawBentRail();

                myEngine.mvMatrixStack.popMatrix();
                myEngine.updateMvMatrix();
            }
            else {
                myEngine.mvMatrixStack.pushMatrix();
                    myEngine.mvMatrixStack.addRotation(-M_PI/2, { 0.0f, 0.0f, 1.0f});
                    myEngine.mvMatrixStack.addTranslation({ 10.0f*-y-10, 10.0f*x, 0});
                    myEngine.updateMvMatrix();

                    drawBentRail();

                myEngine.mvMatrixStack.popMatrix();
                myEngine.updateMvMatrix();
            }
        }
    }
}