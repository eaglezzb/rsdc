/*
 * Copyright (C) 2010-2013 Groupement d'Intérêt Public pour l'Education Numérique en Afrique (GIP ENA)
 *
 * This file is part of Open-Sankoré.
 *
 * Open-Sankoré is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License,
 * with a specific linking exception for the OpenSSL project's
 * "OpenSSL" library (or with modified versions of it that use the
 * same license as the "OpenSSL" library).
 *
 * Open-Sankoré is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Open-Sankoré.  If not, see <http://www.gnu.org/licenses/>.
 */



#include "UBToolsManager.h"

#include "core/memcheck.h"

UBToolsManager* UBToolsManager::sManager = 0;

UBToolsManager* UBToolsManager::manager()
{
    if (!sManager)
        sManager = new UBToolsManager(UBApplication::staticMemoryCleaner);
    return sManager;
}

void UBToolsManager::destroy()
{
    if (sManager)
        delete sManager;
    sManager = NULL;
}


UBToolsManager::UBToolsManager(QObject *parent)
    : QObject(parent)
{

    mask.id = "uniboardTool://uniboard.mnemis.com/mask";
    mask.icon = QPixmap(":/images/toolPalette/maskTool.png");
    mask.label = tr("Mask");
    mask.version = "1.0";
    mToolsIcon.insert(mask.id, ":/images/toolPalette/maskTool.png");
    mDescriptors << mask;

    ruler.id = "uniboardTool://uniboard.mnemis.com/ruler";
    ruler.icon = QPixmap(":/images/toolPalette/rulerTool.png");
    ruler.label = tr("Ruler");
    ruler.version = "1.0";
    mToolsIcon.insert(ruler.id, ":/images/toolPalette/rulerTool.png");
    mDescriptors << ruler;

    compass.id = "uniboardTool://uniboard.mnemis.com/compass";
    compass.icon = QPixmap(":/images/toolPalette/compassTool.png");
    compass.label = tr("Compass");
    compass.version = "1.0";
    mToolsIcon.insert(compass.id, ":/images/toolPalette/compassTool.png");
    mDescriptors << compass;

    protractor.id = "uniboardTool://uniboard.mnemis.com/protractor";
    protractor.icon = QPixmap(":/images/toolPalette/protractorTool.png");
    protractor.label = tr("Protractor");
    protractor.version = "1.0";
    mToolsIcon.insert(protractor.id,":/images/toolPalette/protractorTool.png");
    mDescriptors << protractor;

    triangle.id = "uniboardTool://uniboard.mnemis.com/triangle";
    triangle.icon = QPixmap(":/images/toolPalette/triangleTool.png");
    triangle.label = tr("Triangle");
    triangle.version = "1.0";
    mToolsIcon.insert(triangle.id,":/images/toolPalette/triangleTool.png");
    mDescriptors << triangle;

    magnifier.id = "uniboardTool://uniboard.mnemis.com/magnifier";
    magnifier.icon = QPixmap(":/images/toolPalette/magnifierTool.png");
    magnifier.label = tr("Magnifier");
    magnifier.version = "1.0";
    mToolsIcon.insert(magnifier.id,":/images/toolPalette/magnifierTool.png");
    mDescriptors << magnifier;

//  --------------------------------------------------------------------------------
//  DO NOT ERASE THIS COMMENTED CODE! IT WILL BE UNCOMMENTED DURING THE NEXT DAYS!!!
//  --------------------------------------------------------------------------------
    cache.id = "uniboardTool://uniboard.mnemis.com/cache";
    cache.icon = QPixmap(":/images/toolPalette/cacheTool.png");
    cache.label = tr("Cache");
    cache.version = "1.0";
    mToolsIcon.insert(cache.id, ":/images/toolPalette/cacheTool.png");
    mDescriptors << cache;
//  --------------------------------------------------------------------------------

//    aristo.id = "uniboardTool://uniboard.mnemis.com/aristo";
//    aristo.icon = QPixmap(":/images/toolPalette/aristoTool.png");
//    aristo.label = tr("Aristo");
//    aristo.version = "1.0";
//    mToolsIcon.insert(aristo.id, ":/images/toolPalette/aristoTool.png");
//    mDescriptors << aristo;
}

UBToolsManager::~UBToolsManager()
{
    // NOOP
}
