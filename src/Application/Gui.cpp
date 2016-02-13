#include "Gui.h"

namespace ofx {
namespace piMapper {

Gui * Gui::_instance = 0;

Gui * Gui::instance(){
	if(_instance == 0){
		_instance = new ofx::piMapper::Gui();
	}
	return _instance;
}

void Gui::notifyEvent(ofMouseEventArgs & args){
	GuiEvent e;
	e.args = args;
	e.type = GuiEventType::SURFACE_HIT;
	ofNotifyEvent(event, e, this);
}

void Gui::notifyJointPressed(ofMouseEventArgs & args, int jointIndex){
	GuiJointEvent e;
	e.args = args;
	e.jointIndex = jointIndex;
	ofNotifyEvent(jointPressedEvent, e, this);
}

void Gui::notifyJointReleased(ofMouseEventArgs & args, int jointIndex){
	GuiJointEvent e;
	e.args = args;
	e.jointIndex = jointIndex;
	ofNotifyEvent(jointReleasedEvent, e, this);
}

void Gui::notifyJointDragged(ofMouseEventArgs & args, int jointIndex){
	GuiJointEvent e;
	e.args = args;
	e.jointIndex = jointIndex;
	ofNotifyEvent(jointDraggedEvent, e, this);
}

void Gui::notifySurfacePressed(ofMouseEventArgs & args, BaseSurface * surface){
	GuiSurfaceEvent e;
	e.args = args;
	e.surface = surface;
	ofNotifyEvent(surfacePressedEvent, e, this);
}

void Gui::notifySurfaceReleased(ofMouseEventArgs & args, BaseSurface * surface){
	GuiSurfaceEvent e;
	e.args = args;
	e.surface = surface;
	ofNotifyEvent(surfaceReleasedEvent, e, this);
}

void Gui::notifySurfaceDragged(ofMouseEventArgs & args, BaseSurface * surface){
	GuiSurfaceEvent e;
	e.args = args;
	e.surface = surface;
	ofNotifyEvent(surfaceDraggedEvent, e, this);
}

} // piMapper
} // ofx