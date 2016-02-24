#ifndef GRAPHVIZPOPUP_H
#define GRAPHVIZPOPUP_H
#include <QWheelEvent>
#include <QGraphicsView>

class GraphVizPopUp : public QGraphicsView
{
public:
    GraphVizPopUp();
private:
    void wheelEvent(QWheelEvent *event);
};

#endif // GRAPHVIZPOPUP_H
