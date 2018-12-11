#ifndef QT_CAL_H
#define QT_CAL_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QObject>
#include <QCheckBox>
#include <QRadioButton>
#include <QGroupBox>
class qt_cal:public QWidget
{
    Q_OBJECT
public:
    qt_cal();
    ~qt_cal();
public slots:
    void clearButtonPress();
    void startButtonPress();
    void cb1action();
    void cb2action();
    void cb3action();
    void cb4action();
    void cb5action();
    void cb6action();
    void cb7action();
    void cb8action();
    void cb9action();
    void cb10action();
    void cb11action();
    void cb12action();
    void cb13action();
private:
    QLineEdit *operateEdit1,*operateEdit2,*operateEdit3,*operateEdit4,*operateEdit5;
    QLineEdit *result;
    QPushButton *clearButton;
    QPushButton *startButton;
    QLabel *label1, *label2, *label3, *label4, *label5,*resultlabel;
    QRadioButton *cb1,*cb2,*cb3,*cb4,*cb5,*cb6,*cb7,*cb8,*cb9,*cb10,*cb11,*cb12,*cb13;
    QHBoxLayout *firstLayout;
    QHBoxLayout *secondLayout;
    QHBoxLayout *thirdLayout;
    QHBoxLayout *qhbl1,*qhbl2;
    QHBoxLayout *rightlayout1,*rightlayout2,*rightlayout3,*rightlayout4,*rightlayout5,*rightlayout6,*rightlayout7,*rightlayout8;
    QVBoxLayout *mainLayout1,*mainLayout2;
    QVBoxLayout *final;
    QString input1,input2,input3,input4,input5;
    QGroupBox *gb1,*gb2;


};
class lens
{
private:
    double n,r,d,f,c;
    double l_obj,l_img,u_obj,u_img;
    double i_obj,i_img;
    double x,s_obj,s_img,t_obj,t_img,D;
public:
    void set_n(double n1){this->n=n1;}
    void set_f(double f1){this->f=f1;}
    void set_c(double c1){this->c=c1;}
    void set_r(double r1){this->r=r1;}
    void set_d(double d1){this->d=d1;}
    void set_D(double D1){this->D=D1;}
    void set_l_obj(double l1){this->l_obj=l1;}
    void set_l_img(double l2){this->l_img=l2;}
    void set_u_obj(double u1){this->u_obj=u1;}
    void set_u_img(double u2){this->u_img=u2;}
    void set_i_obj(double i1){this->i_obj=i1;}
    void set_i_img(double i2){this->i_img=i2;}
    void set_x(double x1) {this->x = x1;}
    void set_s_obj(double s1) {this->s_obj = s1;}
    void set_s_img(double s2) {this->s_img = s2;}
    void set_t_obj(double t1) {this->t_obj = t1;}
    void set_t_img(double t2) {this->t_img = t2;}
    double get_n(){return this->n;}
    double get_f(){return this->f;}
    double get_c(){return this->c;}
    double get_r(){return this->r;}
    double get_d(){return this->d;}
    double get_D(){return this->D;}
    double get_l_obj(){return this->l_obj;}
    double get_l_img(){return this->l_img;}
    double get_u_obj(){return this->u_obj;}
    double get_u_img(){return this->u_img;}
    double get_i_obj(){return this->i_obj;}
    double get_i_img(){return this->i_img;}
    double get_x() {return this->x;}
    double get_s_obj(){return this->s_obj;}
    double get_s_img(){return this->s_img;}
    double get_t_obj(){return this->t_obj;}
    double get_t_img(){return this->t_img;}

};
#endif // QT_CAL_H
