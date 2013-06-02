#ifndef __MAPS_H_
#define __MAPS_H_

#include "Level.h"

#define NONE -1

#define OUTSIDE -255

/************************************************************
* Overworld Maps                                            *
************************************************************/
char worldmap_01[23][81] = 
{
	"################################################################################",
	"#                                                                               ",
	"#           o                                                                   ",
	"#                                                                o              ",
	"#                                                                               ",
	"#                                                                               ",
	"#                                                                               ",
	"#                                                                               ",
	"#                                                                               ",
	"#                                                                               ",
	"#                    o                              o                           ",
	"#                                                                               ",
	"#                                                                               ",
	"#                                                                               ",
	"#                                                                               ",
	"#                                                                               ",
	"#                                                                               ",
	"#                                                               o               ",
	"#         o                                                                     ",
	"#                                                                               ",
	"#                                                                               ",
	"#                                                                               ",
	"#                                                                              #"
};
int map1neighbours[4] = {NONE, NONE, 1, 3};
Level map01 = Level(worldmap_01, map1neighbours, BACKGROUND_GREEN);

char worldmap_02[23][81] = 
{
	"################################################################################",
	"                          ######################################################",
	"                                   #############################################",
	"                                           #####################################",
	"                                                ################################",
	"                  o                                      #######################",
	"                                                   o            ################",
	"                                                                       #########",
	"                                                                           #####",
	"                                  o                                       ######",
	"            o                                                               ####",
	"                                                           o               #####",
	"                                                                           #####",
	"                                                                            ####",
	"                                                                           #####",
	"                                                    o                     ######",
	"                   o               o                                            ",
	"                                                                                ",
	"                                                               #################",
	"                                                     ###########################",
	"        #######################              ###################################",
	"     ##############################      #######################################",
	"#####################################  #########################################"
};
int map2neighbours[4] = {0, NONE, 2, 4};
Level map02 = Level(worldmap_02, map2neighbours, BACKGROUND_GREEN);

char worldmap_03[23][81] = 
{
	"################################################################################",
	"########                                        o                  #############",
	"#######                      o                                      ############",
	"#####      o                        ###########################    #############",
	"####                                ###########################    #############",
	"#####           o                   ###########################    #############",
	"####                                ############################o   ############",
	"###                       o        ############################    #############",
	"###    o                           #############################    ############",
	"#####                             ###########################       ############",
	"#############     ###########################################   ################",
	"#############     ##########################################   #################",
	"##########        ###################################               o    #######",
	"########          #################################                       ######",
	"########    #####################################            o             #####",
	"########    #####################################                          #####",
	"           ########################################   o             o     ######",
	"           #########################################                     #######",
	"############################################################    ################",
	"#####################################          #############    ################",
	"#####################################  ##                      #################",
	"#####################################  ########    o          ##################",
	"#####################################  #########################################"
};
int map3neighbours[4] = {1, NONE, NONE, 5};
Level map03 = Level(worldmap_03, map3neighbours, BACKGROUND_RED);

char worldmap_04[23][81] = 
{
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                               ",
	"#                     o                                        ##               ",
	"#         ##                                                   ##              #",
	"#         ##                                          o                        #",
	"#                                                                              #",
	"#                              ##                                              #",
	"#                              ##                                              #",
	"#             o                                                                #",
	"#                                    o                                         #",
	"#                                                                              #",
	"#          o                                        ##           o             #",
	"#                                                   ##                         #",
	"#                                                                              #",
	"#                                                                              #",
	"#         ##       o                   o                                       #",
	"#         ##                                                                   #",
	"#                        ##                                                    #",
	"#                        ##                  ##             o                  #",
	"#                                            ##                                #",
	"#                                                                              #",
	"#                                                                              #"
};
int map4neighbours[4] = {NONE, 0, 4, 6};
Level map04 = Level(worldmap_04, map4neighbours, BACKGROUND_GREEN);

char worldmap_05[23][81] = 
{
	"####################################   #########################################",
	"####################################   #########################################",
	"                                                                                ",
	"                                                                                ",
	"####################################   #########################################",
	"####################################   #########################################",
	"#                                                                              #",
	"#                                                                              #",
	"#         B              B                       B               B             #",
	"#                                                                              #",
	"#         o              o                       o               o             #",
	"#                                                                              #",
	"#         B              B                       B               B             #",
	"#                                                                              #",
	"#         o              o                       o               o             #",
	"#                                                                              #",
	"#         B              B                       B               B             #",
	"#                                                                              #",
	"#         o              o                       o               o             #",
	"#                                                                              #",
	"#LL##                                                                          #",
	"#  #############################################################################",
	"#  #############################################################################"
};
int map5neighbours[4] = {3, 1, 5, 7};
Level map05 = Level(worldmap_05, map5neighbours, BACKGROUND_BLUE);

char worldmap_06[23][81] = 
{
	"####################################  ##########################################",
	"####################################  ##########################################",
	"      ###############################  #########################################",
	"       ###############################  ########################################",
	"#####   ##############################  ########################################",
	"######    ############################  ########################################",
	"######                                                          ################",
	"#####                                                                    #######",
	"#####                                                                   ########",
	"####             B                                                      ########",
	"####                                                  B                 ########",
	"###                                 o                                   ########",
	"###                                                                     ########",
	"####                                                                     #######",
	"####                                                                     #######",
	"#####                    o                         o                   #########",
	"######                                                                ##########",
	"########                                                             ###########",
	"############                                                    ################",
	"##################                  B                      #####################",
	"###########################                      ###############################",
	"################################################################################",
	"################################################################################"
};
int map6neighbours[4] = {4, 2, NONE, NONE};
Level map06 = Level(worldmap_06, map6neighbours, BACKGROUND_RED);

char worldmap_07[23][81] = 
{
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                             ##",
	"#                                                                             ##",
	"#                                                           #                  #",
	"#            #                                                                ##",
	"##                            ######                                         ###",
	"###                           ######                                          ##",
	"#                             ##11##                                         ###",
	"#                                                                             ##",
	"##                                                                            ##",
	"##                                                                             #",
	"###                                                                           ##",
	"###                                                                          ###",
	"##                             #                           #                 ###",
	"###                                                                           ##",
	"###                                                                          ###",
	"###                                                                         ####",
	"##                                                                          ####",
	"##                                                                            ##",
	"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
	"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
	"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
};
int map7neighbours[4] = {NONE, 3, NONE, NONE};
Level map07 = Level(worldmap_07, map7neighbours, BACKGROUND_RED | BACKGROUND_GREEN);

char worldmap_08[23][81] = 
{
	"#  #############################################################################",
	"#  #           #            #           B            o                         #",
	"#  #  ######   # #######    # B            B                      o            #",
	"#  #  #    #   # #  #  #    #    ###########################  ##################",
	"#  #  #   ##   # #  #  #    #    #                 o                     o     #",
	"#  #  ##   #   # #  #  #    #o   #  ############################################",
	"#  #  #    #   #    #  #    #                       o                        o #",
	"#  #    B  #   #       #    #    ###########################################   #",
	"#  #  #    #   #####   #    # B  #      o                     B                #",
	"#  #  ##   #           #    #    #   #    ######################################",
	"#  #  #    #   #####   #         #   #           #            B                #",
	"#     #   ##   #     B #    #   o#   #########   #   #############  ############",
	"#######    #   #   #   #    #        #           #   #                o         ",
	"#       B      #   #   #    #    #   #   #########   # ###################      ",
	"########  ######   #   #    #   B#   #       B   #   #       o           #  ####",
	"#              #   #        #    #   #    #      #   ##################  #  #  #",
	"#  #############   #        #    #   #    #  #####        #         #       #  #",
	"#    o             #   #### ###  #####    #  #       #           #    #  #  #  #",
	"#############  #####   #         o   #    #  #  ############  #########  #  #  #",
	"#              #       #      B      #    #          #       o           #  #  #",
	"#  #############   #   #  ####################  ##########################  #  #",
	"#   B              #   #                   o                                   #",
	"################################################################################"
};
int map8neighbours[4] = {NONE, 4, 8, NONE};
Level map08 = Level(worldmap_08, map8neighbours, BACKGROUND_BLUE);

char worldmap_09[23][81] = 
{
	"################################################################################",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"####                                                                           #",
	"                                     W                                         #",
	"                                                                               #",
	"####                                                                           #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"################################################################################"
};
int map9neighbours[4] = {7, NONE, NONE, NONE};
Level map09 = Level(worldmap_09, map9neighbours, 0);

/************************************************************
* Dungeon 1 Maps                                            *
************************************************************/

char dungeon1_map01[23][81] = 
{
	"#####################################  #########################################",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                            ^                    ^                            #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                    ^                                         #",
	"#                                                                              #",
	"#                                                                              #",
	"#                ^                                        ^                    #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#####################################22#########################################"
};
int dungeon1map1neighbours[4] = {NONE, 10, NONE, OUTSIDE};
Level dungeon1map1 = Level(dungeon1_map01, dungeon1map1neighbours, 0);

char dungeon1_map02[23][81] = 
{
	"#####################################  #########################################",
	"#                               G                                              #",
	"#                               G                                              #",
	"#                               G                                              #",
	"#               B               G                                              #",
	"#                               G                                              #",
	"#                               G                                              #",
	"#                               G                                              #",
	"#                               G                                              #",
	"#          B                    G                                              #",
	"#                               G                                              #",
	"#                B              G                                               ",
	"#                               G                                               ",
	"#          B                    G                                              #",
	"#                               G                                              #",
	"#                               G                                              #",
	"#                               G                                              #",
	"#                               G                                              #",
	"#               B               G                                              #",
	"#                               G                                              #",
	"#                               G                                              #",
	"#                               G                                              #",
	"#####################################  #########################################"
};
int dungeon1map2neighbours[4] = {NONE, 11, 12, 9};
Level dungeon1map2 = Level(dungeon1_map02, dungeon1map2neighbours, 0);

char dungeon1_map03[23][81] = 
{
	"################################################################################",
	"#                                                                              #",
	"#                                                                              #",
	"#                                   B                                          #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                          GGGGGGGGGGGGGGGGGGGGG                               #",
	"#                          G                   G                               #",
	"#       B                  G                   G             B                 #",
	"#                          G         D         G                               #",
	"#                          G                   G                               #",
	"#                          G                   G                               #",
	"#                          G                   G                               #",
	"#                          G                   G                               #",
	"#                          G                   G                               #",
	"#        B                 G                   G             B                 #",
	"#                          G                   G                               #",
	"#                          G                   G                               #",
	"#                          G                   G                               #",
	"#                          G                   G                               #",
	"#                          G                   G                               #",
	"#####################################  #########################################"
};
int dungeon1map3neighbours[4] = {NONE, NONE, NONE, 10};
Level dungeon1map3 = Level(dungeon1_map03, dungeon1map3neighbours, 0);

char dungeon1_map04[23][81] = 
{
	"#####################################  #########################################",
	"#                               G                                              #",
	"#                               G                                              #",
	"#                               G                             ^                #",
	"#               B               G                                              #",
	"#                               G                   ^                          #",
	"#                               G                                              #",
	"#                               G                                              #",
	"#                               G                 ^                            #",
	"#GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG                                              #",
	"#                                                           ^                  #",
	"                 ^                                                             #",
	"                                                                               #",
	"#                                                     ^                        #",
	"#GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG                                              #",
	"#                               G                                              #",
	"#                               G                    ^                         #",
	"#                               G                            ^                 #",
	"#               B               G                                              #",
	"#                               G                                              #",
	"#                               G                                              #",
	"#                               G                                              #",
	"################################################################################"
};
int dungeon1map4neighbours[4] = {10, 13, NONE, NONE};
Level dungeon1map4 = Level(dungeon1_map04, dungeon1map4neighbours, 0);

char dungeon1_map05[23][81] = 
{
	"################################################################################",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                         OOOOOOOOOOOOOOOOOOOOOOOOOOOOO                        #",
	"#                                                                              #",
	"#GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG#",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#                                                                              #",
	"#####################################  #########################################"
	};
int dungeon1map5neighbours[4] = {NONE, NONE, NONE, 12};
Level dungeon1map5 = Level(dungeon1_map05, dungeon1map5neighbours, 0);

#endif