/****************************************************************************
**
 * Draw circle, given its radius and two points on circle

Copyright (C) 2014-2015 Dongxu Li (dongxuli2011 at gmail.com)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
**********************************************************************/
#ifndef LC_ACTIONDRAWCIRCLE2PR_H
#define LC_ACTIONDRAWCIRCLE2PR_H

#include "rs_previewactioninterface.h"
#include "rs_actiondrawcirclecr.h"

/**
 * This action class can handle user events to draw a
 * circle with radius and two points on the circle
 *
 * @author Dongxu Li
 */
class LC_ActionDrawCircle2PR : public RS_ActionDrawCircleCR {
	Q_OBJECT
public:
    /**
     * Action States.
     */
    enum Status {
        SetPoint1,       /**< Setting the 1st point. */
        SetPoint2,       /**< Setting the 2nd point. */
        SelectCenter        /**< select center out of two possibilities. */
    };

public:
    LC_ActionDrawCircle2PR(RS_EntityContainer& container,
                          RS_GraphicView& graphicView);
	~LC_ActionDrawCircle2PR()=default;

    void reset();

    virtual void init(int status=0);
	
    virtual void trigger();
    bool preparePreview(const RS_Vector& mouse);
	
    virtual void mouseMoveEvent(QMouseEvent* e);
    virtual void mouseReleaseEvent(QMouseEvent* e);
	
	virtual void coordinateEvent(RS_CoordinateEvent* e);
    virtual void commandEvent(RS_CommandEvent* e);
    virtual QStringList getAvailableCommands();

    virtual void updateMouseButtonHints();
    virtual void updateMouseCursor();

protected:
    /**
     * 1st point.
     */
    RS_Vector point1;
    /**
     * 2nd point.
     */
    RS_Vector point2;
};

#endif
