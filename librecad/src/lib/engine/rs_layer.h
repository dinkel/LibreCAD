/****************************************************************************
**
** This file is part of the LibreCAD project, a 2D CAD program
**
** Copyright (C) 2015 A. Stebich (librecad@mail.lordofbikes.de)
** Copyright (C) 2010 R. van Twisk (librecad@rvt.dds.nl)
** Copyright (C) 2001-2003 RibbonSoft. All rights reserved.
**
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file gpl-2.0.txt included in the
** packaging of this file.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**
** This copyright notice MUST APPEAR in all copies of the script!
**
**********************************************************************/


#ifndef RS_LAYER_H
#define RS_LAYER_H

#ifdef __hpux
#include <sys/_size_t.h>
#endif

#include <iostream>
#include <QString>

#include "rs_pen.h"


/**
 * Holds the data that defines a layer.
 */
class RS_LayerData {
public:
    RS_LayerData() {}

    RS_LayerData(const QString& name,
                 const RS_Pen& pen,
                 bool frozen,
                 bool locked) {
        this->name = name;
        this->pen = pen;
        this->frozen = frozen;
        this->locked = locked;
    }

    //! Layer name
    QString name;

    //! default pen for this layer
    RS_Pen pen;

    //! Frozen flag
    bool frozen;

    //! Locked flag
    bool locked;

    //! Print flag
    bool print;

    //! Converted flag (cam)
    bool converted;

    //! a construction layer has entities of infinite length, and will never be printed out
    bool construction;

    //! visible in layer list
    bool visibleInLayerList;
};



/**
 * Class for representing a layer
 *
 * @author Andrew Mustun
 */
class RS_Layer {
public:
    explicit RS_Layer(const QString& name);
    //RS_Layer(const char* name);

    RS_Layer* clone() {
        return new RS_Layer(*this);
    }

    /** sets a new name for this layer. */
    void setName(const QString& name) {
        data.name = name;
    }

    /** @return the name of this layer. */
    QString getName() const {
        return data.name;
    }

    /** sets the default pen for this layer. */
    void setPen(const RS_Pen& pen) {
        data.pen = pen;
    }

    /** @return default pen for this layer. */
    RS_Pen getPen() const {
        return data.pen;
    }

    /**
     * @retval true if this layer is frozen (invisible)
     * @retval false if this layer isn't frozen (visible)
     */
    bool isFrozen() const {
        return data.frozen;
        //getFlag(RS2::FlagFrozen);
    }

    /**
     * @retval true the layer has been converted already
     * @retval false the layer still needs to be converted
     */
    bool isConverted() const {
        return data.converted;
    }

    /**
     * Sets the converted flag
     */
    void setConverted(bool c) {
        data.converted = c;
    }

    /**
     * Toggles the visibility of this layer.
     * Freezes the layer if it's not frozen, thaws the layer otherwise
     */
    void toggle() {
        //toggleFlag(RS2::FlagFrozen);
        data.frozen = !data.frozen;
    }

    /**
     * (De-)freezes this layer.
     *
     * @param freeze true: freeze, false: defreeze
     */
    void freeze(bool freeze) {
        data.frozen = freeze;
    }

    /**
     * Toggles the lock of this layer.
     */
    void toggleLock() {
        //toggleFlag(RS2::FlagFrozen);
        data.locked = !data.locked;
    }

    /**
     * Toggles printing of this layer on / off.
     */
    void togglePrint() {
        data.print = !data.print;
    }

    /**
     * Toggles construction attribute of this layer on / off.
     */
    void toggleConstruction() {
        data.construction = !data.construction;
    }

    /**
     * Locks/Unlocks this layer.
     *
     * @param l true: lock, false: unlock
     */
    void lock(bool l) {
        data.locked = l;
    }

    /**
     * return the LOCK state of the Layer
     */
    bool isLocked() {
        return data.locked;
    }

    /**
     * set visibility of layer in layer list
     *
     * @param l true: visible, false: invisible
     */
    void visibleInLayerList(bool l) {
        data.visibleInLayerList = l;
    }

    /**
     * return the visibility of the Layer in layer list
     */
    bool isVisibleInLayerList() {
        return data.visibleInLayerList;
    }

    /**
     * set the PRINT state of the Layer
     *
     * @param print true: print layer, false: don't print layer
     */
    bool setPrint( const bool print) {
        return data.print = print;
    }

    /**
     * return the PRINT state of the Layer
     */
    bool isPrint() {
        return data.print;
    }

    /**
     * whether the layer is a construction layer
     * The construction layer property is stored
     * in extended data in the DXF layer table
     */
    bool isConstruction(){
        return data.construction;
    }

    /**
     * set the construction attribute for the layer
     *
     * @param construction true: infinite lines, false: normal layer
     */
    bool setConstruction( const bool construction){
        data.construction = construction;
        return construction;
    }

    friend std::ostream& operator << (std::ostream& os, const RS_Layer& l);

private:
    //! Layer data
    RS_LayerData data;

};

#endif
