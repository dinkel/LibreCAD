/*
**********************************************************************************
**
** This file is part of the LibreCAD project (librecad.org), a 2D CAD program.
**
** Copyright (C) 2015 ravas (ravas@outlook.com)
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation; either version 2
** of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
**
**********************************************************************************
*/

#ifndef LC_ACTIONFACTORY_H
#define LC_ACTIONFACTORY_H

#include <QAction>
#include <QActionGroup>

#include "qg_actionhandler.h"


class LC_ActionFactory : public QObject
{
    Q_OBJECT

public:
    LC_ActionFactory();
    virtual ~LC_ActionFactory() = default;
    QMap<QString, QAction*> action_map(QG_ActionHandler* action_handler, QObject* main_window, QActionGroup* tools);
};

#endif

