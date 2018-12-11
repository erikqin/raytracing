#include <qt_cal.h>
#include <Qapplication>
#include <qstring>
#include <math.h>
#include <QValidator>
#include <QStringList>
#include <QFile>
#include <QVector>
#include <iostream>
#include <QTextStream>
using namespace std;
double cal(double L, double Y, double WW, double A, double LP, double U1);
double cal_f(double L, double Y, double WW, double A, double LP, double U1);
double cal_c(double L, double Y, double WW, double A, double LP, double U1);
double cal_g(double l, double y, double W, double aper, double Lp1);
double U_img,Uf_img,Uc_img;
QString s_f_img,s_lp_img,s_y_img,s_l_img,s_dl_1,s_dl_707,s_dlc_1,s_dlc_707,s_delta_y_1,s_delta_y_707,s_ch_1,s_ch_707;
QString s_Ks_1,s_Ks_707,s_707_Ks_1,s_707_Ks_707,s_Kt_1,s_Kt_1_707,s_Kt_707,s_Kt_707_707,s_xt,s_xs,s_dx,s_xt_707,s_xs_707,s_dx_707;
QString s_yd_buf[10],s_yf_buf[10],s_yc_buf[10];
qt_cal::qt_cal()
{
    QValidator *validator=new QIntValidator(-10000000000000000,10000000000000000,this);
    label1 = new QLabel(tr("L = "));
    operateEdit1 = new QLineEdit(this);
    operateEdit1 -> setText(tr("0"));
    operateEdit1 ->setValidator(validator);

    label2 = new QLabel(tr("2y = "));
    operateEdit2 = new QLineEdit(this);
    operateEdit2 -> setText(tr("0"));
    operateEdit2 ->setValidator(validator);

    label3 = new QLabel(tr("2W = "));
    operateEdit3 = new QLineEdit(this);
    operateEdit3 -> setText(tr("0"));
    operateEdit3 ->setValidator(validator);

    label4 = new QLabel(tr("2a = "));
    operateEdit4 = new QLineEdit(this);
    operateEdit4 -> setText(tr("0"));
    operateEdit4 ->setValidator(validator);

    label5 = new QLabel(tr("Lp1 = "));
    operateEdit5 = new QLineEdit(this);
    operateEdit5 -> setText(tr("0"));
    operateEdit5 ->setValidator(validator);

    clearButton = new QPushButton;
    clearButton -> setText(tr("Clear"));

    startButton = new QPushButton;
    startButton -> setText(tr("Start calculation!"));

    firstLayout = new QHBoxLayout;
    firstLayout->addWidget(clearButton);
    firstLayout->addWidget(startButton);

    secondLayout = new QHBoxLayout;
    secondLayout ->addWidget(label1);
    secondLayout ->addWidget(operateEdit1);
    secondLayout ->addWidget(label2);
    secondLayout ->addWidget(operateEdit2);
    secondLayout ->addWidget(label3);
    secondLayout -> addWidget(operateEdit3);

    thirdLayout = new QHBoxLayout;
    thirdLayout ->addWidget(label4);
    thirdLayout ->addWidget(operateEdit4);
    thirdLayout ->addWidget(label5);
    thirdLayout -> addWidget (operateEdit5);

    mainLayout1 = new QVBoxLayout;
    mainLayout1 -> addLayout(firstLayout);
    mainLayout1 -> addLayout(secondLayout);
    mainLayout1 ->addLayout(thirdLayout);



    cb1 = new QRadioButton(tr("计算f’ lp’ y0’ l’"));
    cb2 = new QRadioButton(tr("计算轴上点全、0.707孔径球差"));
    cb3 = new QRadioButton(tr("计算轴上点全、0.707孔径位置色差"));
    cb4 = new QRadioButton(tr("计算d光全、0.707视场畸变，全、0.707孔径倍率色差"));
    cb5 = new QRadioButton(tr("计算d光全视场下的全孔径、0.707孔径弧矢彗差"));
    cb6 = new QRadioButton(tr("计算d光0.707视场下的全孔径、0.707孔径弧矢彗差"));
    cb7 = new QRadioButton(tr("计算d光全视场下的全孔径、0.707孔径子午彗差"));
    cb8 = new QRadioButton(tr("计算d光0.707视场下的全孔径、0.707子午彗差"));
    cb9 = new QRadioButton(tr("计算全视场xt', xs', delta_x'"));
    cb10 = new QRadioButton(tr("计算0.707视场xt',xs',delta_x"));
    cb11 = new QRadioButton(tr("d光全视场全孔径、全视场负全孔径、全视场0孔径、全视场0.707孔径、全视场负0.707孔径、0.707视场全孔径、0.707视场负全孔径、0.707视场0孔径、0.707视场0.707孔径、0.707视场负0.707孔径的像高"));
    cb12 = new QRadioButton(tr("f光全视场全孔径、全视场负全孔径、全视场0孔径、全视场0.707孔径、全视场负0.707孔径、0.707视场全孔径、0.707视场负全孔径、0.707视场0孔径、0.707视场0.707孔径、0.707视场负0.707孔径的像高"));
    cb13 = new QRadioButton(tr("c光全视场全孔径、全视场负全孔径、全视场0孔径、全视场0.707孔径、全视场负0.707孔径、0.707视场全孔径、0.707视场负全孔径、0.707视场0孔径、0.707视场0.707孔径、0.707视场负0.707孔径的像高"));

    rightlayout1 = new QHBoxLayout;
    rightlayout1 ->addWidget(cb1);
    rightlayout1 ->addWidget(cb2);

    rightlayout2 = new QHBoxLayout;
    rightlayout2 ->addWidget(cb3);
    rightlayout2 ->addWidget(cb4);

    rightlayout3 = new QHBoxLayout;
    rightlayout3 ->addWidget(cb5);
    rightlayout3 ->addWidget(cb6);

    rightlayout4 = new QHBoxLayout;
    rightlayout4 ->addWidget(cb7);
    rightlayout4 ->addWidget(cb8);

    rightlayout5 = new QHBoxLayout;
    rightlayout5 ->addWidget(cb9);
    rightlayout5 ->addWidget(cb10);

    rightlayout6 = new QHBoxLayout;
    rightlayout6 ->addWidget(cb11);

    rightlayout7 = new QHBoxLayout;
    rightlayout7 ->addWidget(cb12);

    rightlayout8 = new QHBoxLayout;
    rightlayout8 ->addWidget(cb13);

    mainLayout2 = new QVBoxLayout;
    mainLayout2 -> addLayout(rightlayout1);
    mainLayout2 -> addLayout(rightlayout2);
    mainLayout2 -> addLayout(rightlayout3);
    mainLayout2 -> addLayout(rightlayout4);
    mainLayout2 -> addLayout(rightlayout5);
    mainLayout2 -> addLayout(rightlayout6);
    mainLayout2 -> addLayout(rightlayout7);
    mainLayout2 -> addLayout(rightlayout8);

    qhbl1 = new QHBoxLayout;
    qhbl1 ->addLayout(mainLayout1);
    qhbl1 ->addLayout(mainLayout2);
    qhbl2 = new QHBoxLayout;
    resultlabel = new QLabel(tr("Result: "));
    result = new QLineEdit(this);
    result ->setText(tr("0"));
    qhbl2 ->addWidget(resultlabel);
    qhbl2 ->addWidget(result);
    final = new QVBoxLayout;
    final ->addLayout(qhbl1);
    final ->addLayout(qhbl2);
    setLayout(final);
    connect(clearButton,SIGNAL(clicked()),this,SLOT(clearButtonPress()));
    connect(startButton,SIGNAL(clicked()),this,SLOT(startButtonPress()));
    connect(cb1,SIGNAL(clicked()),this,SLOT(cb1action()));
    connect(cb2,SIGNAL(clicked()),this,SLOT(cb2action()));
    connect(cb3,SIGNAL(clicked()),this,SLOT(cb3action()));
    connect(cb4,SIGNAL(clicked()),this,SLOT(cb4action()));
    connect(cb5,SIGNAL(clicked()),this,SLOT(cb5action()));
    connect(cb6,SIGNAL(clicked()),this,SLOT(cb6action()));
    connect(cb7,SIGNAL(clicked()),this,SLOT(cb7action()));
    connect(cb8,SIGNAL(clicked()),this,SLOT(cb8action()));
    connect(cb9,SIGNAL(clicked()),this,SLOT(cb9action()));
    connect(cb10,SIGNAL(clicked()),this,SLOT(cb10action()));
    connect(cb11,SIGNAL(clicked()),this,SLOT(cb11action()));
    connect(cb12,SIGNAL(clicked()),this,SLOT(cb12action()));
    connect(cb13,SIGNAL(clicked()),this,SLOT(cb13action()));
    this->setWindowTitle(tr("Optical Path Calculator"));
    this->setWindowFlags(Qt::WindowMinimizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(1360,230);
    input1 = operateEdit1->text(); input2= operateEdit2->text(); input3= operateEdit3->text();
    input4 = operateEdit4->text(); input5= operateEdit5->text();
}
qt_cal::~qt_cal()
{

    //if(operatorEdit1)
}

void qt_cal::clearButtonPress()
{
    operateEdit1->setText("0");
    operateEdit2->setText("0");
    operateEdit3->setText("0");
    operateEdit4->setText("0");
    operateEdit5->setText("0");
    result ->setText("0");
}
lens a[100];//理想
lens b[100];//实际
int lens_num;

void qt_cal::startButtonPress()
{
    input1 = operateEdit1->text(); input2= operateEdit2->text(); input3= operateEdit3->text();
    input4 = operateEdit4->text(); input5= operateEdit5->text();
    QVector<double> lens_temp(60);
    QFile *file = new QFile("try.txt");
    QStringList strList;
    int j=0;
    QByteArray Explain = file->readLine();
    file ->open(QIODevice::ReadOnly|QIODevice::Text);
    while(!file->atEnd())
    {
        QByteArray line = file->readLine();
        QString str = line.data();
        strList = str.split(" ");
        for (int i=0; i<strList.size();i++)
        {
            lens_temp[j] = strList[i].toDouble();
            j++;
        }
    }
    lens_num = (j+1)/5;
    int i=0;
    double l,y,W,aper,Lp1;
    l=input1.toDouble();y=input2.toDouble()/2;W=input3.toDouble()/2;aper=input4.toDouble()/2; Lp1=input5.toDouble();

   int k=0;
    while ( i<lens_num)
    {
           a[i].set_n(lens_temp[k]);
           a[i].set_f(lens_temp[k+1]);
           a[i].set_c(lens_temp[k+2]);
           a[i].set_r(lens_temp[k+3]);
           a[i].set_d(lens_temp[k+4]);
           i++;
           k+=5;
    }
    a[0].set_l_obj(-1000000000000000);
    a[0].set_l_img(a[0].get_n()/((1/a[0].get_l_obj())+(a[0].get_n()-1)/a[0].get_r()));//第一个透镜

    for (i=1;i<lens_num;i++)
    {
       a[i].set_l_obj(a[i-1].get_l_img()-a[i-1].get_d());
       a[i].set_l_img(a[i].get_n()/((a[i-1].get_n()/a[i].get_l_obj())+(a[i].get_n()-a[i-1].get_n())/a[i].get_r()));
    }
   double l3;
        //l3 = a[lens_num-1].get_l_img();
        //cout<<"l3 = "<<l3<<endl;
   double f_img=1;

   for (i=0;i<lens_num;i++)
       {
           f_img=f_img*a[i].get_l_img();
       }
       for (i=1;i<lens_num;i++)
       {
           f_img=f_img/a[i].get_l_obj();
       }

       /////////////////////l3//////////////////
       a[0].set_l_obj(l);
       a[0].set_l_img(a[0].get_n()/((1/a[0].get_l_obj())+(a[0].get_n()-1)/a[0].get_r()));//第一个透镜
       for (i=1;i<lens_num;i++)
       {
           a[i].set_l_obj(a[i-1].get_l_img()-a[i-1].get_d());
           a[i].set_l_img(a[i].get_n()/((a[i-1].get_n()/a[i].get_l_obj())+(a[i].get_n()-a[i-1].get_n())/a[i].get_r()));
       }
       l3 = a[lens_num-1].get_l_img();
   /////////////计算lp'///////////////
       a[0].set_l_obj(Lp1);
       a[0].set_l_img(a[0].get_n()/((1/Lp1)+(a[0].get_n()-1)/a[0].get_r()));//第一个透镜
       for (i=1;i<lens_num;i++)
       {
           a[i].set_l_obj(a[i-1].get_l_img()-a[i-1].get_d());
           a[i].set_l_img(a[i].get_n()/((a[i-1].get_n()/a[i].get_l_obj())+(a[i].get_n()-a[i-1].get_n())/a[i].get_r()));
       }
       double lp_img;
       lp_img=a[i-1].get_l_img();

     //  cout <<"lp' = "<<lp_img<<endl;
   /////////////////////////////////////////////////////
       a[0].set_l_obj(l);
       a[0].set_u_obj(aper/(Lp1-l));
       a[0].set_i_obj((l-a[0].get_r())/a[0].get_r()*a[0].get_u_obj());
       a[0].set_i_img(a[0].get_i_obj()/a[0].get_n());
       a[0].set_u_img(a[0].get_u_obj()+a[0].get_i_obj()-a[0].get_i_img());
       a[0].set_l_img(a[0].get_r()*(1+a[0].get_i_img()/a[0].get_u_img()));
       for (i=1;i<lens_num;i++)
       {
           a[i].set_l_obj(a[i-1].get_l_img()-a[i-1].get_d());
           a[i].set_u_obj(a[i-1].get_u_img());
           a[i].set_i_obj((a[i].get_l_obj()-a[i].get_r())/a[i].get_r()*a[i].get_u_obj());
           a[i].set_i_img(a[i].get_i_obj()*a[i-1].get_n()/a[i].get_n());
           a[i].set_u_img(a[i].get_u_obj()+a[i].get_i_obj()-a[i].get_i_img());
           a[i].set_l_img(a[i].get_r()*(1+a[i].get_i_img()/a[i].get_u_img()));
       }

   ///////////////高斯像面位置////////////////////////////////
       double l_img;
       l_img = a[lens_num-1].get_l_img();

   //////////////////////计算y'//////////////////////

       double y_img;
       y_img = a[0].get_u_obj()*y/a[lens_num-1].get_u_img();
     //  cout<<"y' = "<<y_img<<endl;//阿贝不变量

   //////////////////////////////////////////////////
      // QString s = QString::number(lens_num,'f',6);
      // result->setText(s);
       //result->setText(s_f_img+" "+s_lp_img+" "+s_y_img+" "+s_l_img);


       double L,Y,WW,A,LP;
       i=0;k=0;
       L=input1.toDouble();Y=input2.toDouble()/2;
       WW=input3.toDouble();A=input4.toDouble()/2;LP=input5.toDouble();
       while (i<lens_num)
       {
              b[i].set_n(lens_temp[k]);
              b[i].set_f(lens_temp[k+1]);
              b[i].set_c(lens_temp[k+2]);
              b[i].set_r(lens_temp[k+3]);
              b[i].set_d(lens_temp[k+4]);
              i++;
              k+=5;
       }


       //////////////////////////////////////
       ////下面计算轴外点实际光线//////
       ////命名规则：U1_bar_Kw_Kn
       double U1_bar_1_p1,U1_bar_1_m1,U1_bar_1_p707,U1_bar_1_m707,U1_bar_1_0;
       double U1_bar_707_p1,U1_bar_707_m1,U1_bar_707_p707,U1_bar_707_m707,U1_bar_707_0;

       U1_bar_1_p1=atan((Y-A/2)/(LP-L)); U1_bar_1_m1=atan((Y+A/2)/(LP-L));
       U1_bar_1_p707=atan((Y-0.707*A/2)/(LP-L)); U1_bar_1_m707=atan((Y+0.707*A/2)/(LP-L));
       U1_bar_1_0=atan(Y/(LP-L));
       U1_bar_707_p1=atan((0.707*Y-A/2)/(LP-L)); U1_bar_707_m1=atan((0.707*Y+A/2)/(LP-L));
       U1_bar_707_p707=atan((0.707*Y-0.707*A/2)/(LP-L)); U1_bar_707_m707=atan((0.707*Y+0.707*A/2)/(LP-L));
       U1_bar_707_0=atan(0.707*Y/(LP-L));

       double L1_bar_1_p1, L1_bar_1_m1, L1_bar_1_p707, L1_bar_1_m707, L1_bar_1_0;
       double L1_bar_707_p1,L1_bar_707_m1,L1_bar_707_p707,L1_bar_707_m707,L1_bar_707_0;
       L1_bar_1_p1=LP+A/2/tan(U1_bar_1_p1); L1_bar_1_m1=LP-A/2/tan(U1_bar_1_m1);
       L1_bar_1_p707=LP+0.707*A/2/tan(U1_bar_1_p707); L1_bar_1_m707=LP-0.707*A/2/tan(U1_bar_1_m707);
       L1_bar_1_0=LP;
       L1_bar_707_p1=LP+A/2/tan(U1_bar_707_p1); L1_bar_707_m1=LP-A/2/tan(U1_bar_707_m1);
       L1_bar_707_p707=LP+0.707*A/2/tan(U1_bar_707_p707); L1_bar_707_m707=LP-0.707*A/2/tan(U1_bar_707_m707);
       L1_bar_707_0=LP;



   //   cout<<"Gaussian : "<<a[lens_num-1].get_l_img()<<endl;
   //      QString g = QString::number(a[lens_num-1].get_l_img(),'f',6);
   //    result->setText(g);

           double dlc_1,dlc_707;
           cout<<"轴上点全孔径球差 ="<<cal(L,Y,WW,A,LP,atan(A/(LP-L)))-a[lens_num-1].get_l_img()<<endl;
           cout<<"轴上点0.707孔径球差 = "<<cal(L,Y,WW,0.707*A,LP,asin(0.707*sin(atan(A/(LP-L)))))-a[lens_num-1].get_l_img()<<endl;
           cout<<"轴上点全孔径位置色差 = "<<cal_f(L,Y,WW,A,LP,atan(A/(LP-L)))-cal_c(L,Y,WW,A,LP,U1_bar_1_0)<<endl;
           cout<<"轴上点0.707孔径位置色差 = "<<cal_f(L,Y,WW,0.707*A,LP,asin(0.707*sin(atan(A/(LP-L)))))-cal_c(L,Y,WW,0.707*A,LP,U1_bar_1_0)<<endl;
           dlc_1 = cal_f(L,Y,WW,A,LP,atan(A/(LP-L)))-cal_c(L,Y,WW,A,LP,U1_bar_1_0);
           dlc_707 = cal_f(L,Y,WW,0.707*A,LP,asin(0.707*sin(atan(A/(LP-L)))))-cal_c(L,Y,WW,0.707*A,LP,U1_bar_1_0);
           //*************************************弧矢彗差***************************************************
           double df_1,df_707,dl_1,dl_707;
           dl_1 = cal(L,Y,WW,A,LP,atan(A/(LP-L)))-a[lens_num-1].get_l_img();
           dl_707 = cal(L,Y,WW,0.707*A,LP,asin(0.707*sin(atan(A/(LP-L)))))-a[lens_num-1].get_l_img();


           b[0].set_l_obj(-1000000000000000);
           b[0].set_u_obj(A/(Lp1+1000000000000000));
           b[0].set_i_obj(asin((b[0].get_l_obj()-b[0].get_r())/b[0].get_r()*sin(b[0].get_u_obj())));
           b[0].set_i_img(asin(sin(b[0].get_i_obj())/b[0].get_n()));
           b[0].set_u_img(b[0].get_u_obj()+b[0].get_i_obj()-b[0].get_i_img());
           b[0].set_l_img(b[0].get_r()+b[0].get_r()*sin(b[0].get_i_img())/sin(b[0].get_u_img()));
           for (i=1;i<lens_num;i++)
           {
               b[i].set_l_obj(b[i-1].get_l_img()-b[i-1].get_d());
               b[i].set_u_obj(b[i-1].get_u_img());
               b[i].set_i_obj(asin((b[i].get_l_obj()-b[i].get_r())/b[i].get_r()*sin(b[i].get_u_obj())));
               b[i].set_i_img(asin(b[i-1].get_n()/b[i].get_n()*sin(b[i].get_i_obj())));
               b[i].set_u_img(b[i].get_u_obj()+b[i].get_i_obj()-b[i].get_i_img());
               b[i].set_l_img(b[i].get_r()+b[i].get_r()*sin(b[i].get_i_img())/sin(b[i].get_u_img()));
           /*    if (abs(b[i].get_i_obj())>3.14/2 || abs(b[i].get_i_img())>3.14/2)
               {
                    cout<<"data error!!"<<endl;
               }
           */
           }
           df_1 = Y/sin(b[lens_num-1].get_u_img())-f_img;

           b[0].set_l_obj(-1000000000000000);
           b[0].set_u_obj(0.707*A/(Lp1+1000000000000000));
           b[0].set_i_obj(asin((b[0].get_l_obj()-b[0].get_r())/b[0].get_r()*sin(b[0].get_u_obj())));
           b[0].set_i_img(asin(sin(b[0].get_i_obj())/b[0].get_n()));
           b[0].set_u_img(b[0].get_u_obj()+b[0].get_i_obj()-b[0].get_i_img());
           b[0].set_l_img(b[0].get_r()+b[0].get_r()*sin(b[0].get_i_img())/sin(b[0].get_u_img()));
           for (i=1;i<lens_num;i++)
           {
               b[i].set_l_obj(b[i-1].get_l_img()-b[i-1].get_d());
               b[i].set_u_obj(b[i-1].get_u_img());
               b[i].set_i_obj(asin((b[i].get_l_obj()-b[i].get_r())/b[i].get_r()*sin(b[i].get_u_obj())));
               b[i].set_i_img(asin(b[i-1].get_n()/b[i].get_n()*sin(b[i].get_i_obj())));
               b[i].set_u_img(b[i].get_u_obj()+b[i].get_i_obj()-b[i].get_i_img());
               b[i].set_l_img(b[i].get_r()+b[i].get_r()*sin(b[i].get_i_img())/sin(b[i].get_u_img()));
            /*
               if (abs(b[i].get_i_obj())>3.14/2 || abs(b[i].get_i_img())>3.14/2)
               {
                    cout<<"data error!!"<<endl;
               }
             */
           }
           df_707 = Y/sin(b[lens_num-1].get_u_img())-f_img;
           double OSC_1, OSC_707;
           OSC_1 = df_1/f_img-dl_1/(a[lens_num-1].get_l_img()-lp_img);
           OSC_707 = df_707/f_img-dl_707/(a[lens_num-1].get_l_img()-lp_img);
           double Ks_1, Ks_707;
           Ks_1 = OSC_1*y_img; Ks_707 = OSC_707*y_img;
           cout<<"Ks' (全孔径, 全视场) = "<<Ks_1<<'\n'<<"Ks' (0.707孔径，全视场) = "<<Ks_707<<endl;
           cout<<"Ks' (全孔径, 0.707视场) = "<<0.707*Ks_1<<'\n'<<"Ks' (0.707孔径，0.707视场) = "<<0.707*Ks_707<<endl;

       /////////////////////////////////////////////////////////////////////////////////////



           double ya,yb,yp;
           double yd_buf[10], yf_buf[10], yc_buf[10];
           k=0;
           cout<<"全视场+全孔径 d F C光像高, d光彗差、畸变："<<endl;
           yd_buf[k] = (cal(L1_bar_1_p1, Y, WW, A,LP,U1_bar_1_p1)-a[lens_num-1].get_l_img())*tan(U_img);
           yf_buf[k] = (cal_f(L1_bar_1_p1, Y, WW, A,LP,U1_bar_1_p1)-a[lens_num-1].get_l_img())*tan(Uf_img);
           yc_buf[k] = (cal_c(L1_bar_1_p1, Y, WW, A,LP,U1_bar_1_p1)-a[lens_num-1].get_l_img())*tan(Uc_img);
           ya=(cal(L1_bar_1_p1, Y, WW, A,LP,U1_bar_1_p1)-a[lens_num-1].get_l_img())*tan(U_img);
           cout<<" y'_d= "<<yd_buf[k]<<endl;
           cout<<" y'_F="<<yf_buf[k]<<endl;
           cout<<" y'_C= "<<yc_buf[k]<<endl;
           k++;
              cout<<"********************************************************************"<<endl;
           cout<<"全视场-全孔径 d F C光像高： "<<endl;
           yd_buf[k] = (cal(L1_bar_1_m1, Y, WW, A,LP,U1_bar_1_m1)-a[lens_num-1].get_l_img())*tan(U_img);
           yf_buf[k] = (cal_f(L1_bar_1_m1, Y, WW, A,LP,U1_bar_1_m1)-a[lens_num-1].get_l_img())*tan(Uf_img);
           yc_buf[k] = (cal_c(L1_bar_1_m1, Y, WW, A,LP,U1_bar_1_m1)-a[lens_num-1].get_l_img())*tan(Uc_img);
           cout<<" y'_d= "<<(cal(L1_bar_1_m1, Y, WW, A,LP,U1_bar_1_m1)-a[lens_num-1].get_l_img())*tan(U_img)<<endl;
           yb=(cal(L1_bar_1_m1, Y, WW, A,LP,U1_bar_1_m1)-a[lens_num-1].get_l_img())*tan(U_img);
           cout<<" y'_F="<< (cal_f(L1_bar_1_m1, Y, WW, A,LP,U1_bar_1_m1)-a[lens_num-1].get_l_img())*tan(Uf_img)<<endl;
           cout<<" y'_C= "<<(cal_c(L1_bar_1_m1, Y, WW, A,LP,U1_bar_1_m1)-a[lens_num-1].get_l_img())*tan(Uc_img)<<endl;
           k++;
              cout<<"********************************************************************"<<endl;
           cout<<"全视场0孔径 d F C光像高："<<endl;
           double delta_y_1, Kt_1,ch_1;
           yd_buf[k] = (cal(L1_bar_1_0, Y, WW, A,LP,U1_bar_1_0)-a[lens_num-1].get_l_img())*tan(U_img);
           yf_buf[k] = (cal_f(L1_bar_1_0, Y, WW, A,LP,U1_bar_1_0)-a[lens_num-1].get_l_img())*tan(Uf_img);
           yc_buf[k] = (cal_c(L1_bar_1_0, Y, WW, A,LP,U1_bar_1_0)-a[lens_num-1].get_l_img())*tan(Uc_img);
           cout<<" y'_d="<< (cal(L1_bar_1_0, Y, WW, A,LP,U1_bar_1_0)-a[lens_num-1].get_l_img())*tan(U_img)<<endl;
           yp=(cal(L1_bar_1_0, Y, WW, A,LP,U1_bar_1_0)-a[lens_num-1].get_l_img())*tan(U_img);
           cout<<" delta_y=" <<(cal(L1_bar_1_0, Y, WW, A,LP,U1_bar_1_0)-a[lens_num-1].get_l_img())*tan(U_img)-y_img<<endl;
           delta_y_1 = (cal(L1_bar_1_0, Y, WW, A,LP,U1_bar_1_0)-a[lens_num-1].get_l_img())*tan(U_img)-y_img;
           ch_1 = (cal_f(L1_bar_1_0, Y, WW, A,LP,U1_bar_1_0)-a[lens_num-1].get_l_img())*tan(Uf_img)-(cal_c(L1_bar_1_0, Y, WW, A,LP,U1_bar_1_0)-a[lens_num-1].get_l_img())*tan(Uc_img);
           cout<<"全视场倍率色差 = "<<ch_1<<endl;
           cout<<" y'_F="<< (cal_f(L1_bar_1_0, Y, WW, A,LP,U1_bar_1_0)-a[lens_num-1].get_l_img())*tan(Uf_img)<<endl;
           cout<<" y'_C="<< (cal_c(L1_bar_1_0, Y, WW, A,LP,U1_bar_1_0)-a[lens_num-1].get_l_img())*tan(Uc_img)<<endl;
           Kt_1= (ya+yb)/2-yp;
           cout<<"全视场全孔径d光子午彗差 = "<<(ya+yb)/2-yp<<endl;
           k++;
       ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
              cout<<"********************************************************************"<<endl;
           cout<<"全视场+0.707孔径 d F C光像高："<<endl;
           yd_buf[k] = (cal(L1_bar_1_p707, Y, WW, A,LP,U1_bar_1_p707)-a[lens_num-1].get_l_img())*tan(U_img);
           yf_buf[k] = (cal_f(L1_bar_1_p707, Y, WW, A,LP,U1_bar_1_p707)-a[lens_num-1].get_l_img())*tan(Uf_img);
           yc_buf[k] = (cal_c(L1_bar_1_p707, Y, WW, A,LP,U1_bar_1_p707)-a[lens_num-1].get_l_img())*tan(Uc_img);
           cout<<" y'_d= "<<(cal(L1_bar_1_p707, Y, WW, A,LP,U1_bar_1_p707)-a[lens_num-1].get_l_img())*tan(U_img)<<endl;
           cout<<" y'_F="<< (cal_f(L1_bar_1_p707, Y, WW, A,LP,U1_bar_1_p707)-a[lens_num-1].get_l_img())*tan(Uf_img)<<endl;
           cout<<" y'_C="<< (cal_c(L1_bar_1_p707, Y, WW, A,LP,U1_bar_1_p707)-a[lens_num-1].get_l_img())*tan(Uc_img)<<endl;
           ya = yd_buf[k];
           k++;
             cout<<"********************************************************************"<<endl;
           cout<<"全视场-0.707孔径 d F C光像高："<<endl;
           yd_buf[k] = (cal(L1_bar_1_m707, Y, WW, A,LP,U1_bar_1_m707)-a[lens_num-1].get_l_img())*tan(U_img);
           yf_buf[k] = (cal_f(L1_bar_1_m707, Y, WW, A,LP,U1_bar_1_m707)-a[lens_num-1].get_l_img())*tan(Uf_img);
           yc_buf[k] = (cal_c(L1_bar_1_m707, Y, WW, A,LP,U1_bar_1_m707)-a[lens_num-1].get_l_img())*tan(Uc_img);
           cout<<" y'_d="<< (cal(L1_bar_1_m707, Y, WW, A,LP,U1_bar_1_m707)-a[lens_num-1].get_l_img())*tan(U_img)<<endl;
           cout<<" y'_F="<< (cal_f(L1_bar_1_m707, Y, WW, A,LP,U1_bar_1_m707)-a[lens_num-1].get_l_img())*tan(Uf_img)<<endl;
           cout<<" y'_C="<< (cal_c(L1_bar_1_m707, Y, WW, A,LP,U1_bar_1_m707)-a[lens_num-1].get_l_img())*tan(Uc_img)<<endl;
           yb = yd_buf[k];
           k++;
           double Kt_1_707;
           Kt_1_707 = (ya+yb)/2-yp;//0.707孔径全视场
       ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
              cout<<"********************************************************************"<<endl;
           cout<<"0.707视场+全孔径 d F C光像高: "<<endl;
           yd_buf[k] = (cal(L1_bar_707_p1, Y, WW, A,LP,U1_bar_707_p1)-a[lens_num-1].get_l_img())*tan(U_img);
           yf_buf[k] = (cal_f(L1_bar_707_p1, Y, WW, A,LP,U1_bar_707_p1)-a[lens_num-1].get_l_img())*tan(Uf_img);
           yc_buf[k] = (cal_c(L1_bar_707_p1, Y, WW, A,LP,U1_bar_707_p1)-a[lens_num-1].get_l_img())*tan(Uc_img);
           cout<<" y'_d="<< (cal(L1_bar_707_p1, Y, WW, A,LP,U1_bar_707_p1)-a[lens_num-1].get_l_img())*tan(U_img)<<endl;
           ya=(cal(L1_bar_707_p1, Y, WW, A,LP,U1_bar_707_p1)-a[lens_num-1].get_l_img())*tan(U_img);
           cout<<" y'_F="<< (cal_f(L1_bar_707_p1, Y, WW, A,LP,U1_bar_707_p1)-a[lens_num-1].get_l_img())*tan(Uf_img)<<endl;
           cout<<" y'_C="<< (cal_c(L1_bar_707_p1, Y, WW, A,LP,U1_bar_707_p1)-a[lens_num-1].get_l_img())*tan(Uc_img)<<endl;
           k++;
          cout<<"********************************************************************"<<endl;
           cout<<"0.707视场-全孔径 d F C光像高："<<endl;
           yd_buf[k] = (cal(L1_bar_707_m1, Y, WW, A,LP,U1_bar_707_m1)-a[lens_num-1].get_l_img())*tan(U_img);
           yf_buf[k] = (cal_f(L1_bar_707_m1, Y, WW, A,LP,U1_bar_707_m1)-a[lens_num-1].get_l_img())*tan(Uf_img);
           yc_buf[k] = (cal_c(L1_bar_707_m1, Y, WW, A,LP,U1_bar_707_m1)-a[lens_num-1].get_l_img())*tan(Uc_img);
           cout<<" y'_d="<< (cal(L1_bar_707_m1, Y, WW, A,LP,U1_bar_707_m1)-a[lens_num-1].get_l_img())*tan(U_img)<<endl;
           yb=(cal(L1_bar_707_m1, Y, WW, A,LP,U1_bar_707_m1)-a[lens_num-1].get_l_img())*tan(U_img);
           cout<<" y'_F="<< (cal_f(L1_bar_707_m1, Y, WW, A,LP,U1_bar_707_m1)-a[lens_num-1].get_l_img())*tan(Uf_img)<<endl;
           cout<<" y'_C="<< (cal_c(L1_bar_707_m1, Y, WW, A,LP,U1_bar_707_m1)-a[lens_num-1].get_l_img())*tan(Uc_img)<<endl;
           k++;
          cout<<"********************************************************************"<<endl;
           cout<<"0.707视场0孔径 d F C光像高："<<endl;
           double delta_y_707, Kt_707, ch_707;
           yd_buf[k] = (cal(L1_bar_707_0, Y, WW, A,LP,U1_bar_707_0)-a[lens_num-1].get_l_img())*tan(U_img);
           yf_buf[k] = (cal_f(L1_bar_707_0, Y, WW, A,LP,U1_bar_707_0)-a[lens_num-1].get_l_img())*tan(Uf_img);
           yc_buf[k] = (cal_c(L1_bar_707_0, Y, WW, A,LP,U1_bar_707_0)-a[lens_num-1].get_l_img())*tan(Uc_img);
           cout<<" y'_d="<< (cal(L1_bar_707_0, Y, WW, A,LP,U1_bar_707_0)-a[lens_num-1].get_l_img())*tan(U_img)<<endl;
           yp=(cal(L1_bar_707_0, Y, WW, A,LP,U1_bar_707_0)-a[lens_num-1].get_l_img())*tan(U_img);
           ch_707=(cal_f(L1_bar_707_0, Y, WW, A,LP,U1_bar_707_0)-a[lens_num-1].get_l_img())*tan(Uf_img)-(cal_c(L1_bar_707_0, Y, WW, A,LP,U1_bar_707_0)-a[lens_num-1].get_l_img())*tan(Uc_img);
           cout<<" 0.707视场倍率色差 = "<<ch_707<<endl;
           cout<<" delta_y="<<(cal(L1_bar_707_0, Y, WW, A,LP,U1_bar_707_0)-a[lens_num-1].get_l_img())*tan(U_img)-0.707*y_img<<endl;
           delta_y_707=(cal(L1_bar_707_0, Y, WW, A,LP,U1_bar_707_0)-a[lens_num-1].get_l_img())*tan(U_img)-0.707*y_img;
           cout<<" y'_F="<< (cal_f(L1_bar_707_0, Y, WW, A,LP,U1_bar_707_0)-a[lens_num-1].get_l_img())*tan(Uf_img)<<endl;
           cout<<" y'_C="<< (cal_c(L1_bar_707_0, Y, WW, A,LP,U1_bar_707_0)-a[lens_num-1].get_l_img())*tan(Uc_img)<<endl;
           cout<<"0.707视场 d光子午彗差 = "<<(ya+yb)/2-yp<<endl;
           Kt_707 = (ya+yb)/2-yp;//0.707视场全孔径子午彗差
       //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
           k++;
              cout<<"********************************************************************"<<endl;
           cout<<"0.707视场+0.707孔径 d F C光像高："<<endl;
           yd_buf[k] = (cal(L1_bar_707_p707, Y, WW, A,LP,U1_bar_707_p707)-a[lens_num-1].get_l_img())*tan(U_img);
           yf_buf[k] = (cal_f(L1_bar_707_p707, Y, WW, A,LP,U1_bar_707_p707)-a[lens_num-1].get_l_img())*tan(Uf_img);
           yc_buf[k] = (cal_c(L1_bar_707_p707, Y, WW, A,LP,U1_bar_707_p707)-a[lens_num-1].get_l_img())*tan(Uc_img);
           cout<<" y'_d="<< (cal(L1_bar_707_p707, Y, WW, A,LP,U1_bar_707_p707)-a[lens_num-1].get_l_img())*tan(U_img)<<endl;
           cout<<" y'_F="<< (cal_f(L1_bar_707_p707, Y, WW, A,LP,U1_bar_707_p707)-a[lens_num-1].get_l_img())*tan(Uf_img)<<endl;
           cout<<" y'_C="<< (cal_c(L1_bar_707_p707, Y, WW, A,LP,U1_bar_707_p707)-a[lens_num-1].get_l_img())*tan(Uc_img)<<endl;
           ya = yd_buf[k];
           k++;
              cout<<"********************************************************************"<<endl;
           cout<<"0.707视场-0.707孔径 d F C光像高："<<endl;
           yd_buf[k] = (cal(L1_bar_707_m707, Y, WW, A,LP,U1_bar_707_m707)-a[lens_num-1].get_l_img())*tan(U_img);
           yf_buf[k] = (cal_f(L1_bar_707_m707, Y, WW, A,LP,U1_bar_707_m707)-a[lens_num-1].get_l_img())*tan(Uf_img);
           yc_buf[k] = (cal_c(L1_bar_707_m707, Y, WW, A,LP,U1_bar_707_m707)-a[lens_num-1].get_l_img())*tan(Uc_img);
           cout<<" y'_d="<< (cal(L1_bar_707_m707, Y, WW, A,LP,U1_bar_707_m707)-a[lens_num-1].get_l_img())*tan(U_img)<<endl;
           cout<<" y'_F="<< (cal_f(L1_bar_707_m707, Y, WW, A,LP,U1_bar_707_m707)-a[lens_num-1].get_l_img())*tan(Uf_img)<<endl;
           cout<<" y'_C="<< (cal_c(L1_bar_707_m707, Y, WW, A,LP,U1_bar_707_m707)-a[lens_num-1].get_l_img())*tan(Uc_img)<<endl;
           yb = yd_buf[k];
           double Kt_707_707;
           Kt_707_707 = (ya+yb)/2-yp;//0.707孔径0.707视场子午彗差
       ///*******************************场曲、像散(全视场)**************************************************************
           double UU;//此时UU=WW；
           UU=Y/(LP-L);
       //	cout<<"UU = "<<UU<<endl;
           b[0].set_l_obj(LP);
           b[0].set_u_obj(UU);
           if (UU)
               b[0].set_i_obj(asin((LP-b[0].get_r())/b[0].get_r()*sin(b[0].get_u_obj())));
           else
               b[0].set_i_obj(Y/b[0].get_r());
           double h;
           h = LP/(L-LP)*Y;
           b[0].set_i_img(asin(sin(b[0].get_i_obj())/b[0].get_n()));
           b[0].set_u_img(b[0].get_u_obj()+b[0].get_i_obj()-b[0].get_i_img());
           b[0].set_l_img(b[0].get_r()+b[0].get_r()*sin(b[0].get_i_img())/sin(b[0].get_u_img()));
           b[0].set_x((LP*sin(UU)/cos((b[0].get_i_obj()-b[0].get_u_obj())/2))*(LP*sin(UU)/cos((b[0].get_i_obj()-b[0].get_u_obj())/2))/2/b[0].get_r());
       //	cout<<"x = "<<b[0].get_x()<<endl;;
       //	b[0].set_t_obj(-1000000000000000);
           b[0].set_t_obj((h-Y)/sin(b[0].get_u_obj()));
           b[0].set_s_obj(b[0].get_t_obj());
           double a1;
           a1= (b[0].get_n()*cos(b[0].get_i_img())-cos(b[0].get_i_obj()))/b[0].get_r();
           double c1;
           c1=cos(b[0].get_i_obj())*cos(b[0].get_i_obj())/b[0].get_t_obj()+a1;
           b[0].set_t_img(b[0].get_n()*cos(b[0].get_i_img())*cos(b[0].get_i_img())/c1);
           double kk;
           kk = 1/b[0].get_s_obj()+a1;
           b[0].set_s_img(b[0].get_n()/kk);
           for (i=1;i<lens_num;i++)
           {
               b[i].set_l_obj(b[i-1].get_l_img()-b[i-1].get_d());
               b[i].set_u_obj(b[i-1].get_u_img());
               b[i].set_i_obj(asin((b[i].get_l_obj()-b[i].get_r())/b[i].get_r()*sin(b[i].get_u_obj())));
               b[i].set_i_img(asin(b[i-1].get_n()/b[i].get_n()*sin(b[i].get_i_obj())));
               b[i].set_u_img(b[i].get_u_obj()+b[i].get_i_obj()-b[i].get_i_img());
               b[i].set_l_img(b[i].get_r()+b[i].get_r()*sin(b[i].get_i_img())/sin(b[i].get_u_img()));
               b[i].set_x((b[i].get_l_img()*sin(b[i].get_u_img())/cos((b[i].get_i_img()-b[i].get_u_img())/2))*(b[i].get_l_img()*sin(b[i].get_u_img())/cos((b[i].get_i_img()-b[i].get_u_img())/2))/2/b[i].get_r());
               b[i-1].set_D((b[i-1].get_d()-b[i-1].get_x()+b[i].get_x())/cos(b[i-1].get_u_img()));
               b[i].set_t_obj(b[i-1].get_t_img()-b[i-1].get_D());
               b[i].set_s_obj(b[i-1].get_s_img()-b[i-1].get_D());
               a1 = (b[i].get_n()*cos(b[i].get_i_img())-b[i-1].get_n()*cos(b[i].get_i_obj()))/b[i].get_r();
               c1 = b[i-1].get_n()*cos(b[i].get_i_obj())*cos(b[i].get_i_obj())/b[i].get_t_obj()+a1;
               b[i].set_t_img(b[i].get_n()*cos(b[i].get_i_img())*cos(b[i].get_i_img())/c1);
               kk = b[i-1].get_n()/b[i].get_s_obj()+a1;
               b[i].set_s_img(b[i].get_n()/kk);
            /*   if (abs(b[i].get_i_obj())>3.14/2 || abs(b[i].get_i_img())>3.14/2)
               {
                    cout<<"data error!!"<<endl;
               }
            */
           }
           double xt,xs,dx;
           xt=b[lens_num-1].get_t_img()*cos(b[lens_num-1].get_u_img())+b[lens_num-1].get_x()-l3;
           xs=b[lens_num-1].get_s_img()*cos(b[lens_num-1].get_u_img())+b[lens_num-1].get_x()-l3;
           dx=xt-xs;
           cout<<"xt  xs  dx"<<endl;
           cout<<xt<<' '<<xs<<' '<<dx<<endl;

           //**********************************************************************************************************************///
           ///*******************************场曲、像散(0.707视场)**************************************************************
           //	double UU;//此时UU=WW；
               UU=atan(0.707*Y/(LP-L));
           //	UU=3.179826/180*3.1415926;
           //	cout<<"UU = "<<UU<<endl;
               LP=0;
               b[0].set_l_obj(LP);
               b[0].set_u_obj(UU);
               if (UU)
                   b[0].set_i_obj(asin((LP-b[0].get_r())/b[0].get_r()*sin(b[0].get_u_obj())));
               else
                   b[0].set_i_obj(Y/b[0].get_r());
               h = -0.707*LP/(L-LP)*Y;

               b[0].set_i_img(asin(sin(b[0].get_i_obj())/b[0].get_n()));
               b[0].set_u_img(b[0].get_u_obj()+b[0].get_i_obj()-b[0].get_i_img());
               b[0].set_l_img(b[0].get_r()+b[0].get_r()*sin(b[0].get_i_img())/sin(b[0].get_u_img()));
               b[0].set_x((LP*sin(UU)/cos((b[0].get_i_obj()-b[0].get_u_obj())/2))*(LP*sin(UU)/cos((b[0].get_i_obj()-b[0].get_u_obj())/2))/2/b[0].get_r());
           //	cout<<"x = "<<b[0].get_x()<<endl;;
           //	b[0].set_t_obj(-1000000000000000);
               //cout<<Y;
               b[0].set_t_obj(0.707*(h-Y)/sin(b[0].get_u_obj()));
               //cout<<b[0].get_t_obj()<<"aaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
               b[0].set_s_obj(b[0].get_t_obj());
           //	double a;
               a1= (b[0].get_n()*cos(b[0].get_i_img())-cos(b[0].get_i_obj()))/b[0].get_r();
           //	double c;
               c1=cos(b[0].get_i_obj())*cos(b[0].get_i_obj())/b[0].get_t_obj()+a1;
               b[0].set_t_img(b[0].get_n()*cos(b[0].get_i_img())*cos(b[0].get_i_img())/c1);
           //	double kk;
               kk = 1/b[0].get_s_obj()+a1;
               b[0].set_s_img(b[0].get_n()/kk);
               for (i=1;i<lens_num;i++)
               {
                   b[i].set_l_obj(b[i-1].get_l_img()-b[i-1].get_d());
                   b[i].set_u_obj(b[i-1].get_u_img());
                   b[i].set_i_obj(asin((b[i].get_l_obj()-b[i].get_r())/b[i].get_r()*sin(b[i].get_u_obj())));
                   b[i].set_i_img(asin(b[i-1].get_n()/b[i].get_n()*sin(b[i].get_i_obj())));
                   b[i].set_u_img(b[i].get_u_obj()+b[i].get_i_obj()-b[i].get_i_img());
                   b[i].set_l_img(b[i].get_r()+b[i].get_r()*sin(b[i].get_i_img())/sin(b[i].get_u_img()));
                   b[i].set_x((b[i].get_l_img()*sin(b[i].get_u_img())/cos((b[i].get_i_img()-b[i].get_u_img())/2))*(b[i].get_l_img()*sin(b[i].get_u_img())/cos((b[i].get_i_img()-b[i].get_u_img())/2))/2/b[i].get_r());
                   b[i-1].set_D((b[i-1].get_d()-b[i-1].get_x()+b[i].get_x())/cos(b[i-1].get_u_img()));
                   b[i].set_t_obj(b[i-1].get_t_img()-b[i-1].get_D());
                   b[i].set_s_obj(b[i-1].get_s_img()-b[i-1].get_D());
                   a1 = (b[i].get_n()*cos(b[i].get_i_img())-b[i-1].get_n()*cos(b[i].get_i_obj()))/b[i].get_r();
                   c1 = b[i-1].get_n()*cos(b[i].get_i_obj())*cos(b[i].get_i_obj())/b[i].get_t_obj()+a1;
                   b[i].set_t_img(b[i].get_n()*cos(b[i].get_i_img())*cos(b[i].get_i_img())/c1);
                   kk = b[i-1].get_n()/b[i].get_s_obj()+a1;
                   b[i].set_s_img(b[i].get_n()/kk);
                /*   if (abs(b[i].get_i_obj())>3.14/2 || abs(b[i].get_i_img())>3.14/2)
                   {
                        cout<<"data error!!"<<endl;
                   }
                */
               }
               double xt_707,xs_707,dx_707;
               xt_707=b[lens_num-1].get_t_img()*cos(b[lens_num-1].get_u_img())+b[lens_num-1].get_x()-l3;
               xs_707=b[lens_num-1].get_s_img()*cos(b[lens_num-1].get_u_img())+b[lens_num-1].get_x()-l3;
           //	cout<<b[lens_num-1].get_t_img()<<' '<<cos(b[lens_num-1].get_u_img())<<' '<<b[lens_num-1].get_x()<<' '<<l3<<endl;
               dx_707=xt_707-xs_707;
               cout<<"0.707视场的 xt  xs  dx"<<endl;
               cout<<xt_707<<' '<<xs_707<<' '<<dx_707<<endl;
              s_f_img = QString::number(f_img,'f',6);
              s_lp_img = QString::number(lp_img,'f',6);
              s_l_img = QString::number(l_img,'f',6);
              s_y_img = QString::number(y_img,'f',6);

              s_dlc_1 = QString::number(dlc_1,'f',6);
              s_dlc_707 = QString::number(dlc_707,'f',6);
              s_dl_1 = QString::number(dl_1,'f',6);
              s_dl_707 = QString::number(dl_707,'f',6);

              s_delta_y_1 = QString::number(delta_y_1,'f',6);
              s_delta_y_707 = QString::number(delta_y_707,'f',6);
              s_ch_1 = QString::number(ch_1,'f',6);
              s_ch_707 = QString::number(ch_707,'f',6);
              s_Ks_1 = QString::number(Ks_1,'f',6);
              s_Ks_707 = QString::number(Ks_707,'f',6);
              s_707_Ks_1 = QString::number(0.707*Ks_1,'f',6);
               s_707_Ks_707 = QString::number(0.707*Ks_707,'f',6);
             s_Kt_1 = QString::number(Kt_1,'f',6);
             s_Kt_1_707 = QString::number(Kt_1_707,'f',6);
             s_Kt_707 = QString ::number(Kt_707,'f',6);
              s_Kt_707_707 = QString::number(Kt_707_707,'f',6);
              s_xt = QString::number(xt,'f',6);
              s_xs = QString::number(xs,'f',6);
              s_dx = QString::number(dx,'f',6);
              s_xt_707 = QString::number(xt_707,'f',6);
              s_xs_707 = QString::number(xs_707,'f',6);
              s_dx_707 = QString::number(dx_707,'f',6);

               for (i=0;i<10;i++)
               {
                   s_yd_buf[i]= QString::number(yd_buf[i],'f',6);
                   s_yf_buf[i] = QString::number(yf_buf[i],'f',6);
                   s_yc_buf[i] = QString::number(yc_buf[i],'f',6);
               }

}
void qt_cal::cb1action()
{

    result->setText(s_f_img+" "+s_lp_img+" "+s_l_img+" "+s_y_img);
}
void qt_cal::cb2action()
{
    result->setText(s_dl_1+" "+s_dl_707);
}
void qt_cal::cb3action()
{
    result->setText(s_dlc_1+" "+s_dlc_707);
}
void qt_cal::cb4action()
{
    result->setText(s_delta_y_1+" "+s_delta_y_707+" "+s_ch_1+" "+s_ch_707);
}
void qt_cal::cb5action()
{
    result->setText(s_Ks_1+" "+s_Ks_707);
}
void qt_cal::cb6action()
{
    result->setText(s_707_Ks_1+" "+s_707_Ks_707);
}
void qt_cal::cb7action()
{
    result->setText(s_Kt_1+" "+s_Kt_1_707);
}
void qt_cal::cb8action()
{
    result->setText(s_Kt_707+" "+s_Kt_707_707);
}
void qt_cal::cb9action()
{
    result->setText(s_xt+" "+s_xs+" "+s_dx);
}
void qt_cal::cb10action()
{
    result->setText(s_xt_707+" "+s_xs_707+" "+s_dx_707);
}
void qt_cal::cb11action()
{
    QString st;
    for (int i=0;i<10;i++)
    {
        st = st + s_yd_buf[i];
        st+=" ";
    }
    result->setText(st);
}
void qt_cal::cb12action()
{
    QString st;
    for (int i=0;i<10;i++)
    {
        st = st + s_yf_buf[i];
        st+=" ";
    }
    result->setText(st);
}
void qt_cal::cb13action()
{
    QString st;
    for (int i=0;i<10;i++)
    {
        st = st + s_yc_buf[i];
        st+=" ";
    }
    result->setText(st);
}
double cal(double L, double Y, double WW, double A, double LP, double U1)
{
    int i;
    b[0].set_l_obj(L);
    b[0].set_u_obj(U1);
    if (U1)
      b[0].set_i_obj(asin((L-b[0].get_r())/b[0].get_r()*sin(b[0].get_u_obj())));
    else
      b[0].set_i_obj(Y/a[0].get_r());
    b[0].set_i_img(asin(sin(b[0].get_i_obj())/b[0].get_n()));
    b[0].set_u_img(b[0].get_u_obj()+b[0].get_i_obj()-b[0].get_i_img());
    b[0].set_l_img(b[0].get_r()+b[0].get_r()*sin(b[0].get_i_img())/sin(b[0].get_u_img()));


    for (i=1;i<lens_num;i++)
    {
        b[i].set_l_obj(b[i-1].get_l_img()-b[i-1].get_d());
        b[i].set_u_obj(b[i-1].get_u_img());
        b[i].set_i_obj(asin((b[i].get_l_obj()-b[i].get_r())/b[i].get_r()*sin(b[i].get_u_obj())));
        b[i].set_i_img(asin(b[i-1].get_n()/b[i].get_n()*sin(b[i].get_i_obj())));
        b[i].set_u_img(b[i].get_u_obj()+b[i].get_i_obj()-b[i].get_i_img());
        b[i].set_l_img(b[i].get_r()+b[i].get_r()*sin(b[i].get_i_img())/sin(b[i].get_u_img()));
    //	cout<<"PA = "<<b[i].get_l_obj()*sin(b[i].get_u_obj())/cos((b[i].get_i_obj()-b[i].get_u_obj())/2)<<endl;
    //	cout<<"PA' = "<<b[i].get_l_img()*sin(b[i].get_u_img())/cos((b[i].get_i_img()-b[i].get_u_img())/2)<<endl;
    /*    if (abs(b[i].get_i_obj())>3.14/2 || abs(b[i].get_i_img())>3.14/2)
        {
             cout<<"data error!!"<<endl;
        }
    */

    }

   U_img = b[lens_num-1].get_u_img();

   //cout<<"PA' = "<<b[lens_num-1].get_l_img()*sin(U_img)/cos((b[lens_num-1].get_i_img()-U_img)/2)<<endl;
   //cout<<"PA  ="<<L*sin(U1)/cos((b[0].get_i_obj()-U1)/2)<<endl;
   return b[lens_num-1].get_l_img();
}

double cal_f(double L, double Y, double WW, double A, double LP,double U1)
{
    int i;
    b[0].set_l_obj(L);
    b[0].set_u_obj(U1);
    if (U1)
      b[0].set_i_obj(asin((L-b[0].get_r())/b[0].get_r()*sin(b[0].get_u_obj())));
    else
      b[0].set_i_obj(Y/a[0].get_r());
    b[0].set_i_img(asin(sin(b[0].get_i_obj())/b[0].get_f()));
    b[0].set_u_img(b[0].get_u_obj()+b[0].get_i_obj()-b[0].get_i_img());
    b[0].set_l_img(b[0].get_r()+b[0].get_r()*sin(b[0].get_i_img())/sin(b[0].get_u_img()));


    for (i=1;i<lens_num;i++)
    {
        b[i].set_l_obj(b[i-1].get_l_img()-b[i-1].get_d());
        b[i].set_u_obj(b[i-1].get_u_img());
        b[i].set_i_obj(asin((b[i].get_l_obj()-b[i].get_r())/b[i].get_r()*sin(b[i].get_u_obj())));
        b[i].set_i_img(asin(b[i-1].get_f()/b[i].get_f()*sin(b[i].get_i_obj())));
        b[i].set_u_img(b[i].get_u_obj()+b[i].get_i_obj()-b[i].get_i_img());
        b[i].set_l_img(b[i].get_r()+b[i].get_r()*sin(b[i].get_i_img())/sin(b[i].get_u_img()));
      /*  if (abs(b[i].get_i_obj())>(3.14/2) || abs(b[i].get_i_img())>(3.14/2))
        {
             cout<<"data error!!"<<endl;
        }
       */
    }
    Uf_img = b[lens_num-1].get_u_img();
    //cout<<b[lens_num-1].get_u_img();
   return b[lens_num-1].get_l_img();
}

double cal_c(double L, double Y, double WW, double A, double LP,double U1)
{
    int i;
    b[0].set_l_obj(L);
    b[0].set_u_obj(U1);
    if (U1)
      b[0].set_i_obj(asin((L-b[0].get_r())/b[0].get_r()*sin(b[0].get_u_obj())));
    else
      b[0].set_i_obj(Y/a[0].get_r());
    b[0].set_i_img(asin(sin(b[0].get_i_obj())/b[0].get_c()));
    b[0].set_u_img(b[0].get_u_obj()+b[0].get_i_obj()-b[0].get_i_img());
    b[0].set_l_img(b[0].get_r()+b[0].get_r()*sin(b[0].get_i_img())/sin(b[0].get_u_img()));


    for (i=1;i<lens_num;i++)
    {
        b[i].set_l_obj(b[i-1].get_l_img()-b[i-1].get_d());
        b[i].set_u_obj(b[i-1].get_u_img());
        b[i].set_i_obj(asin((b[i].get_l_obj()-b[i].get_r())/b[i].get_r()*sin(b[i].get_u_obj())));
        b[i].set_i_img(asin(b[i-1].get_c()/b[i].get_c()*sin(b[i].get_i_obj())));
        b[i].set_u_img(b[i].get_u_obj()+b[i].get_i_obj()-b[i].get_i_img());
        b[i].set_l_img(b[i].get_r()+b[i].get_r()*sin(b[i].get_i_img())/sin(b[i].get_u_img()));
      /*  if (abs(b[i].get_i_obj())>3.14/2 || abs(b[i].get_i_img())>3.14/2)
        {
             cout<<"data error!!"<<endl;
        }
        */
    }
    Uc_img = b[lens_num-1].get_u_img();
   return b[lens_num-1].get_l_img();


}
