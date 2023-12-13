#ifndef DELETEIOBJECT_H
#define DELETEIOBJECT_H

#include <QWidget>

namespace Ui {
class DeleteIObject;
}

class DeleteIObject : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteIObject(QWidget *parent = nullptr);
    ~DeleteIObject();

private:
    Ui::DeleteIObject *ui;
};

#endif // DELETEIOBJECT_H
