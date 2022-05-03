#ifndef SIMPLENOTEPAD_H
#define SIMPLENOTEPAD_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class simplenotepad; }
QT_END_NAMESPACE

class simplenotepad : public QMainWindow
{
    Q_OBJECT

public:
    simplenotepad(QWidget *parent = nullptr);
    ~simplenotepad();

private slots:
    void on_actionSave_as_triggered();

    void on_actionOpen_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionGo_to_begin_triggered();

    void on_actionGo_to_end_triggered();

    void on_actionNew_triggered();

private:
    Ui::simplenotepad *ui;
};
#endif // SIMPLENOTEPAD_H
