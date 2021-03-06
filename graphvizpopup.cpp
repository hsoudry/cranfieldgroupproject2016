#include "graphvizpopup.h"

GraphVizPopUp::GraphVizPopUp()
{

}

void GraphVizPopUp::wheelEvent(QWheelEvent *event){

    this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    // Scale the view / do the zoom
    double scaleFactor = 1.15;
    if(event->delta() > 0) {

        // Zoom in

        this->scale(scaleFactor, scaleFactor);

    } else {
        // Zooming out
        this->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
    }

}
