/***************************************************************************
  qgsvectortilelayerproperties.h
  --------------------------------------
  Date                 : May 2020
  Copyright            : (C) 2020 by Martin Dobias
  Email                : wonder dot sk at gmail dot com
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSVECTORTILELAYERPROPERTIES_H
#define QGSVECTORTILELAYERPROPERTIES_H

#include "qgsoptionsdialogbase.h"

#include "ui_qgsvectortilelayerpropertiesbase.h"

class QgsMapLayer;
class QgsMapCanvas;
class QgsMessageBar;
class QgsVectorTileBasicLabelingWidget;
class QgsVectorTileBasicRendererWidget;
class QgsVectorTileLayer;


class QgsVectorTileLayerProperties : public QgsOptionsDialogBase, private Ui::QgsVectorTileLayerPropertiesBase
{
    Q_OBJECT
  public:
    QgsVectorTileLayerProperties( QgsVectorTileLayer *lyr, QgsMapCanvas *canvas, QgsMessageBar *messageBar, QWidget *parent = nullptr, Qt::WindowFlags = QgsGuiUtils::ModalDialogFlags );

  private slots:
    void apply();

    void loadDefaultStyle();
    void saveDefaultStyle();
    void loadStyle();
    void saveStyleAs();
    void aboutToShowStyleMenu();
    void showHelp();

  private:
    void syncToLayer();

  private:
    QgsVectorTileLayer *mLayer = nullptr;

    QgsVectorTileBasicRendererWidget *mRendererWidget = nullptr;
    QgsVectorTileBasicLabelingWidget *mLabelingWidget = nullptr;
};

#endif // QGSVECTORTILELAYERPROPERTIES_H
