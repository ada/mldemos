/*********************************************************************
MLDemos: A User-Friendly visualization toolkit for machine learning
Copyright (C) 2010  Basilio Noris
Contact: mldemos@b4silio.com

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License,
version 3 as published by the Free Software Foundation.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free
Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*********************************************************************/
#ifndef _INTERFACEMLPCLASSIFIER_H_
#define _INTERFACEMLPCLASSIFIER_H_

#include <vector>
#include <interfaces.h>
#include "classifierMLP.h"
#include "ui_paramsMLP.h"

class ClassMLP : public QObject, public ClassifierInterface
{
	Q_OBJECT
	Q_INTERFACES(ClassifierInterface)
private:
	QWidget *widget;
	Ui::ParametersMLP *params;
public:
	ClassMLP();
	// virtual functions to manage the algorithm creation
	Classifier *GetClassifier();
	void DrawInfo(Canvas *canvas, Classifier *classifier);
	void Draw(Canvas *canvas, Classifier *classifier);

	// virtual functions to manage the GUI and I/O
	QString GetName(){return QString("MLP");};
	bool UsesDrawTimer(){return true;};
	QWidget *GetParameterWidget(){return widget;};
	void SetParams(Classifier *classifier);
	void SaveOptions(QSettings &settings);
	bool LoadOptions(QSettings &settings);
	void SaveParams(std::ofstream &stream);
	bool LoadParams(char *line, float value);
};

#endif // _INTERFACEMLPCLASSIFIER_H_