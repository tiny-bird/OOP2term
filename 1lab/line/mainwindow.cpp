#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <ctime>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QDesktopWidget>
using namespace std;

const int sizen = 9;
int score = 0;
cell arr[sizen][sizen];

bool locked = false;
int a_x, a_y, b_x, b_y;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    QRect rec = QApplication::desktop()->screenGeometry();
    int hgt = rec.height();
    int wth = rec.width();

    ui->setupUi(this);

   {
    push_button[0][0] = ui->pushButton;
    push_button[0][1] = ui->pushButton_2;
    push_button[0][2] = ui->pushButton_3;
    push_button[0][3] = ui->pushButton_4;
    push_button[0][4] = ui->pushButton_5;
    push_button[0][5] = ui->pushButton_6;
    push_button[0][6] = ui->pushButton_7;
    push_button[0][7] = ui->pushButton_8;
    push_button[0][8] = ui->pushButton_9;
    push_button[1][0] = ui->pushButton_10;
    push_button[1][1] = ui->pushButton_11;
    push_button[1][2] = ui->pushButton_12;
    push_button[1][3] = ui->pushButton_13;
    push_button[1][4] = ui->pushButton_14;
    push_button[1][5] = ui->pushButton_15;
    push_button[1][6] = ui->pushButton_16;
    push_button[1][7] = ui->pushButton_17;
    push_button[1][8] = ui->pushButton_18;
    push_button[2][0] = ui->pushButton_19;
    push_button[2][1] = ui->pushButton_20;
    push_button[2][2] = ui->pushButton_21;
    push_button[2][3] = ui->pushButton_22;
    push_button[2][4] = ui->pushButton_23;
    push_button[2][5] = ui->pushButton_24;
    push_button[2][6] = ui->pushButton_25;
    push_button[2][7] = ui->pushButton_26;
    push_button[2][8] = ui->pushButton_27;
    push_button[3][0] = ui->pushButton_28;
    push_button[3][1] = ui->pushButton_29;
    push_button[3][2] = ui->pushButton_30;
    push_button[3][3] = ui->pushButton_31;
    push_button[3][4] = ui->pushButton_32;
    push_button[3][5] = ui->pushButton_33;
    push_button[3][6] = ui->pushButton_34;
    push_button[3][7] = ui->pushButton_35;
    push_button[3][8] = ui->pushButton_36;
    push_button[4][0] = ui->pushButton_37;
    push_button[4][1] = ui->pushButton_38;
    push_button[4][2] = ui->pushButton_39;
    push_button[4][3] = ui->pushButton_40;
    push_button[4][4] = ui->pushButton_41;
    push_button[4][5] = ui->pushButton_42;
    push_button[4][6] = ui->pushButton_43;
    push_button[4][7] = ui->pushButton_44;
    push_button[4][8] = ui->pushButton_45;
    push_button[5][0] = ui->pushButton_46;
    push_button[5][1] = ui->pushButton_47;
    push_button[5][2] = ui->pushButton_48;
    push_button[5][3] = ui->pushButton_49;
    push_button[5][4] = ui->pushButton_50;
    push_button[5][5] = ui->pushButton_51;
    push_button[5][6] = ui->pushButton_52;
    push_button[5][7] = ui->pushButton_53;
    push_button[5][8] = ui->pushButton_54;
    push_button[6][0] = ui->pushButton_55;
    push_button[6][1] = ui->pushButton_56;
    push_button[6][2] = ui->pushButton_57;
    push_button[6][3] = ui->pushButton_58;
    push_button[6][4] = ui->pushButton_59;
    push_button[6][5] = ui->pushButton_60;
    push_button[6][6] = ui->pushButton_61;
    push_button[6][7] = ui->pushButton_62;
    push_button[6][8] = ui->pushButton_63;
    push_button[7][0] = ui->pushButton_64;
    push_button[7][1] = ui->pushButton_65;
    push_button[7][2] = ui->pushButton_66;
    push_button[7][3] = ui->pushButton_67;
    push_button[7][4] = ui->pushButton_68;
    push_button[7][5] = ui->pushButton_69;
    push_button[7][6] = ui->pushButton_70;
    push_button[7][7] = ui->pushButton_71;
    push_button[7][8] = ui->pushButton_72;
    push_button[8][0] = ui->pushButton_73;
    push_button[8][1] = ui->pushButton_74;
    push_button[8][2] = ui->pushButton_75;
    push_button[8][3] = ui->pushButton_76;
    push_button[8][4] = ui->pushButton_77;
    push_button[8][5] = ui->pushButton_78;
    push_button[8][6] = ui->pushButton_79;
    push_button[8][7] = ui->pushButton_80;
    push_button[8][8] = ui->pushButton_81;
    }
    for (int i = 0; i < 8; i++)
       for (int j = 0; j < 8; j++)
    push_button[i][j]->setStyleSheet("background-color: beige");

    int lower = (wth < hgt) ? wth : hgt;
    int resol = lower/sizen - 5;
    int padding = abs((wth - hgt)/2);

    for (int i = 0; i < sizen; i++)
       for (int j = 0; j < sizen; j++)
       {
           if (hgt < wth)
           {
               push_button[i][j]->setGeometry(padding + i * resol, j * resol , resol,resol);
               push_button[i][j]->setIconSize(QSize(resol,resol));

                ui->label->setGeometry(QRect( padding/2 - 15, hgt/2,60,30));
           }
           else
           {
               push_button[i][j]->setGeometry(i * resol, padding +  j * resol , resol,resol);
               push_button[i][j]->setIconSize(QSize(resol,resol));
               ui->label->setGeometry(QRect(wth/2,padding/2 - 15,60,30));
           }
       }
}

MainWindow::~MainWindow()
{

    delete ui;

}

void MainWindow::initialization()
{
    for (int i = 0; i < sizen; i++)
    {
        for (int j = 0; j < sizen; j++)
        {
            arr[i][j].empty = true;
            arr[i][j].color = -1;
        }
    }
}

void MainWindow::make_new_points()
{
    for (int k = 0; k < 3; k++)
    {
        int new_x, new_y, color;
        while (true)
        {
            new_x = rand() % 9;
            new_y = rand() % 9;
            color = rand() % 7;
            if (arr[new_x][new_y].empty == true)
            {
                arr[new_x][new_y].color = color;
                arr[new_x][new_y].empty = false;
                break;
            }
        }

    }
}

bool MainWindow::lose_check()
{
    int not_empt = 0;
    for (int i = 0; i < sizen; i++)
    {
        for (int j = 0; j < sizen; j++)
        {
            if (!arr[i][j].empty) not_empt++;
        }
    }
    if (not_empt+3 > sizen*sizen)
    {
        return true;
     }       else
    {
        return false;
    }
}
void MainWindow::score_inc(int p)
{
    switch (p)
    {
    case 5:
        score+=2;
        break;
    case 6:
        score+=6;
        break;
    case 7:
        score+=10;
        break;
    case 8:
        score+=14;
        break;
    }


}
void MainWindow::visited()
{
    for (int i=0; i < sizen; i++)
        for (int j=0; j<sizen; j++)
            arr[i][j].visited = false;
}
bool MainWindow::check_line()
{
    for (int i = 0; i < sizen - 4; i++)
    {
        for (int j = 0; j < sizen; j++)
        {
            cell temp = arr[i][j];
            if (!temp.empty)
            {
                if ((temp.color != -1) && (arr[i + 1][j].color == temp.color) && (arr[i + 2][j].color == temp.color) && (arr[i + 3][j].color == temp.color) && (arr[i + 4][j].color == temp.color))
                {
                    arr[i][j].empty = arr[i + 1][j].empty = arr[i + 2][j].empty = arr[i + 3][j].empty = arr[i + 4][j].empty = true;
                    arr[i][j].color = arr[i + 1][j].color = arr[i + 2][j].color = arr[i + 3][j].color = arr[i + 4][j].color = -1;
                    score +=10;
                    for (int p = 5; p < sizen; p++)
                    {
                        if (arr[i + p][j].color == temp.color)
                        {
                            score_inc(p);
                            arr[i + p][j].empty = true;
                            arr[i + p][j].color = -1;
                        }
                        else
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < sizen; i++)
    {
        for (int j = 0; j < sizen - 4; j++)
        {
            cell temp = arr[i][j];
            if (!temp.empty)
            {
                if ((temp.color != -1) && (arr[i][j + 1].color == temp.color) && (arr[i][j + 2].color == temp.color) && (arr[i][j + 3].color == temp.color) && (arr[i][j + 4].color == temp.color))
                {
                    arr[i][j].empty = arr[i][j + 1].empty = arr[i][j + 2].empty = arr[i][j + 3].empty = arr[i][j + 4].empty = true;
                    arr[i][j].color = arr[i][j + 1].color = arr[i][j + 2].color = arr[i][j + 3].color = arr[i][j + 4].color = -1;
                    score +=10;
                    for (int p = 5; p < sizen; p++)
                    {
                        if (arr[i][j + p].color == temp.color)
                        {
                            score_inc(p);
                            arr[i][j + p].empty = true;
                            arr[i][j + p].color = -1;
                        }
                        else
                        {
                             return true;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < sizen -4; i++)
    {
        for (int j = 0; j < sizen -4; j++)
        {
            cell temp = arr[i][j];
            if (!temp.empty)
            {
                if ((temp.color != -1) && (arr[i + 1][j + 1].color == temp.color) && (arr[i + 2][j + 2].color == temp.color) && (arr[i + 3][j + 3].color == temp.color) && (arr[i + 4][j + 4].color == temp.color))
                {
                    arr[i][j].empty = arr[i + 1][j + 1].empty = arr[i + 2][j + 2].empty = arr[i + 3][j + 3].empty = arr[i + 4][j + 4].empty = true;
                    arr[i][j].color = arr[i + 1][j + 1].color = arr[i + 2][j + 2].color = arr[i + 3][j + 3].color = arr[i + 4][j + 4].color = -1;
                    score +=10;
                    for (int p = 5; p < sizen; p++)
                    {
                        if (arr[i + p][j + p].color == temp.color)
                        {
                            score_inc(p);
                            arr[i + p][j + p].empty = true;
                            arr[i + p][j + p].color = -1;
                        }
                        else
                        {
                            return true;

                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < sizen-4; i++)
    {
        for (int j = 4; j < sizen; j++)
        {
            cell temp = arr[i][j];
            if (!temp.empty)
            {
                if ((temp.color != -1) && (arr[i + 1][j - 1].color == temp.color) && (arr[i + 2][j - 2].color == temp.color) && (arr[i + 3][j - 3].color == temp.color) && (arr[i + 4][j - 4].color == temp.color))
                {
                    arr[i][j].empty = arr[i + 1][j - 1].empty = arr[i + 2][j - 2].empty = arr[i + 3][j - 3].empty = arr[i + 4][j - 4].empty = true;
                    arr[i][j].color = arr[i + 1][j - 1].color = arr[i + 2][j - 2].color = arr[i + 3][j - 3].color = arr[i + 4][j - 4].color = -1;
                    score +=10;
                    for (int p = 5; p < sizen; p++)
                    {
                        if (arr[i + p][j - p].color == temp.color)
                        {
                            score_inc(p);
                            arr[i + p][j - p].empty = true;
                            arr[i + p][j - p].color = -1;
                        }
                        else
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
  return false;
}

bool MainWindow::pass_find(int ax, int ay, int bx, int by)
{
   bool flag;
   if (arr[ax][ay].visited)
   {
    return false;
   }
   else
   {
    arr[ax][ay].visited = true;
    if ((ax == bx) && (ay == by))
    {
    return true;
    }
    else
    {
        if ((ax + 1 < sizen) && (arr[ax+1][ay].empty))
        {
           flag = pass_find(ax+1, ay, bx, by);
           if (flag) return true;
        }

        if ((ax - 1 >= 0) && (arr[ax-1][ay].empty))
        {
           flag = pass_find(ax-1, ay, bx, by);
           if (flag) return true;
        }

        if ((ay + 1 < sizen) && (arr[ax][ay+1].empty))
        {
           flag = pass_find(ax, ay+1, bx, by);
           if (flag) return true;
        }

        if ((ay - 1 >= 0) && (arr[ax][ay-1].empty))
        {
           flag = pass_find(ax, ay-1, bx, by);
           if (flag) return true;
        }
    }

   }
return false;
}


void MainWindow::remake()
{
    for (int i=0; i<sizen; i++)
     {
        for (int j = 0; j < sizen; j++)
        {
            switch (arr[i][j].color)
            {
            case 0:
                push_button[i][j]->setStyleSheet("background-color: orange");
                break;
            case 1:
            push_button[i][j]->setStyleSheet("background-color: blue");
                break;
            case 2:
            push_button[i][j]->setStyleSheet("background-color: green");
                break;
            case 3:
            push_button[i][j]->setStyleSheet("background-color: yellow");
                break;
            case 4:
            push_button[i][j]->setStyleSheet("background-color: blueviolet");
                break;
            case 5:
            push_button[i][j]->setStyleSheet("background-color: red");
                break;
            case 6:
            push_button[i][j]->setStyleSheet("background-color: black");
                break;
            case -1:
            push_button[i][j]->setStyleSheet("background-color: beige");
                break;
            }
        }
    }
    ui->label->setText((QString)"Score: "+QString::number(score));
}
void MainWindow::Mouse_click(int ind_x,int ind_y)
{
    if (lose_check())
    {
        QMessageBox msg;
        msg.setText("You lose");
        msg.exec();
    }
    else
    {
    if (!locked)
     {
         visited();
        a_x = ind_x;
        a_y = ind_y;
        if (!arr[a_x][a_y].empty) locked = true;
     }
    else
     {

        b_x = ind_x;
        b_y = ind_y;

            if (arr[b_x][b_y].empty)
            {
                if (pass_find(a_x,a_y,b_x,b_y))
               {

                 arr[b_x][b_y].color = arr[a_x][a_y].color;
                 arr[b_x][b_y].empty = false;
                 arr[a_x][a_y].empty = true;
                 arr[a_x][a_y].color = -1;
                 if (!check_line()) make_new_points();
                 check_line();
                 remake();
                 locked = false;
                }
                else locked = false;
            }
            else locked = false;
       }
    }
}

void MainWindow::on_pushButton_clicked()
{
    Mouse_click(0, 0);
}

void MainWindow::on_pushButton_2_clicked()
{
    Mouse_click(0, 1);
}

void MainWindow::on_pushButton_3_clicked()
{
     Mouse_click(0, 2);
}

void MainWindow::on_pushButton_4_clicked()
{
    Mouse_click(0, 3);
}

void MainWindow::on_pushButton_5_clicked()
{
    Mouse_click(0, 4);
}

void MainWindow::on_pushButton_6_clicked()
{
    Mouse_click(0, 5);
}

void MainWindow::on_pushButton_7_clicked()
{
    Mouse_click(0, 6);
}

void MainWindow::on_pushButton_8_clicked()
{
    Mouse_click(0, 7);
}

void MainWindow::on_pushButton_9_clicked()
{
    Mouse_click(0, 8);
}

void MainWindow::on_pushButton_10_clicked()
{
    Mouse_click(1, 0);
}

void MainWindow::on_pushButton_11_clicked()
{
    Mouse_click(1, 1);
}

void MainWindow::on_pushButton_12_clicked()
{
    Mouse_click(1, 2);
}

void MainWindow::on_pushButton_13_clicked()
{
    Mouse_click(1, 3);
}

void MainWindow::on_pushButton_14_clicked()
{
    Mouse_click(1, 4);
}

void MainWindow::on_pushButton_15_clicked()
{
    Mouse_click(1, 5);
}

void MainWindow::on_pushButton_16_clicked()
{
    Mouse_click(1, 6);
}

void MainWindow::on_pushButton_17_clicked()
{
    Mouse_click(1, 7);
}

void MainWindow::on_pushButton_18_clicked()
{
    Mouse_click(1, 8);
}

void MainWindow::on_pushButton_19_clicked()
{
    Mouse_click(2, 0);
}

void MainWindow::on_pushButton_20_clicked()
{
    Mouse_click(2, 1);
}

void MainWindow::on_pushButton_21_clicked()
{
    Mouse_click(2, 2);
}

void MainWindow::on_pushButton_22_clicked()
{
    Mouse_click(2, 3);
}

void MainWindow::on_pushButton_23_clicked()
{
    Mouse_click(2, 4);
}

void MainWindow::on_pushButton_24_clicked()
{
    Mouse_click(2, 5);
}

void MainWindow::on_pushButton_25_clicked()
{
    Mouse_click(2, 6);
}

void MainWindow::on_pushButton_26_clicked()
{
    Mouse_click(2, 7);
}

void MainWindow::on_pushButton_27_clicked()
{
    Mouse_click(2, 8);
}

void MainWindow::on_pushButton_28_clicked()
{
    Mouse_click(3, 0);
}

void MainWindow::on_pushButton_29_clicked()
{
    Mouse_click(3, 1);
}

void MainWindow::on_pushButton_30_clicked()
{
    Mouse_click(3, 2);
}

void MainWindow::on_pushButton_31_clicked()
{
    Mouse_click(3, 3);
}

void MainWindow::on_pushButton_32_clicked()
{
    Mouse_click(3, 4);
}

void MainWindow::on_pushButton_33_clicked()
{
    Mouse_click(3, 5);
}

void MainWindow::on_pushButton_34_clicked()
{
    Mouse_click(3, 6);
}

void MainWindow::on_pushButton_35_clicked()
{
    Mouse_click(3, 7);
}

void MainWindow::on_pushButton_36_clicked()
{
    Mouse_click(3, 8);
}

void MainWindow::on_pushButton_37_clicked()
{
    Mouse_click(4, 0);
}

void MainWindow::on_pushButton_38_clicked()
{
    Mouse_click(4, 1);
}

void MainWindow::on_pushButton_39_clicked()
{
    Mouse_click(4, 2);
}

void MainWindow::on_pushButton_40_clicked()
{
    Mouse_click(4, 3);
}

void MainWindow::on_pushButton_41_clicked()
{
    Mouse_click(4, 4);
}

void MainWindow::on_pushButton_42_clicked()
{
    Mouse_click(4, 5);
}

void MainWindow::on_pushButton_43_clicked()
{
    Mouse_click(4, 6);
}

void MainWindow::on_pushButton_44_clicked()
{
    Mouse_click(4, 7);
}

void MainWindow::on_pushButton_45_clicked()
{
    Mouse_click(4, 8);
}

void MainWindow::on_pushButton_46_clicked()
{
    Mouse_click(5, 0);
}

void MainWindow::on_pushButton_47_clicked()
{
    Mouse_click(5, 1);
}

void MainWindow::on_pushButton_48_clicked()
{
    Mouse_click(5, 2);
}

void MainWindow::on_pushButton_49_clicked()
{
    Mouse_click(5, 3);
}

void MainWindow::on_pushButton_50_clicked()
{
    Mouse_click(5, 4);
}

void MainWindow::on_pushButton_51_clicked()
{
    Mouse_click(5, 5);
}

void MainWindow::on_pushButton_52_clicked()
{
    Mouse_click(5, 6);
}

void MainWindow::on_pushButton_53_clicked()
{
    Mouse_click(5, 7);
}

void MainWindow::on_pushButton_54_clicked()
{
    Mouse_click(5, 8);
}

void MainWindow::on_pushButton_55_clicked()
{
    Mouse_click(6, 0);
}

void MainWindow::on_pushButton_56_clicked()
{
    Mouse_click(6, 1);
}

void MainWindow::on_pushButton_57_clicked()
{
    Mouse_click(6, 2);
}

void MainWindow::on_pushButton_58_clicked()
{
    Mouse_click(6, 3);
}

void MainWindow::on_pushButton_59_clicked()
{
    Mouse_click(6, 4);
}

void MainWindow::on_pushButton_60_clicked()
{
    Mouse_click(6, 5);
}

void MainWindow::on_pushButton_61_clicked()
{
    Mouse_click(6, 6);
}

void MainWindow::on_pushButton_62_clicked()
{
    Mouse_click(6, 7);
}

void MainWindow::on_pushButton_63_clicked()
{
    Mouse_click(6, 8);
}

void MainWindow::on_pushButton_64_clicked()
{
    Mouse_click(7, 0);
}

void MainWindow::on_pushButton_65_clicked()
{
    Mouse_click(7, 1);
}

void MainWindow::on_pushButton_66_clicked()
{
    Mouse_click(7, 2);
}

void MainWindow::on_pushButton_67_clicked()
{
    Mouse_click(7, 3);
}

void MainWindow::on_pushButton_68_clicked()
{
    Mouse_click(7, 4);
}

void MainWindow::on_pushButton_69_clicked()
{
    Mouse_click(7, 5);
}

void MainWindow::on_pushButton_70_clicked()
{
    Mouse_click(7, 6);
}

void MainWindow::on_pushButton_71_clicked()
{
    Mouse_click(7, 7);
}

void MainWindow::on_pushButton_72_clicked()
{
    Mouse_click(7, 8);
}

void MainWindow::on_pushButton_73_clicked()
{
    Mouse_click(8, 0);
}

void MainWindow::on_pushButton_74_clicked()
{
    Mouse_click(8, 1);
}

void MainWindow::on_pushButton_75_clicked()
{
    Mouse_click(8, 2);
}

void MainWindow::on_pushButton_76_clicked()
{
    Mouse_click(8, 3);
}

void MainWindow::on_pushButton_77_clicked()
{
    Mouse_click(8, 4);
}

void MainWindow::on_pushButton_78_clicked()
{
    Mouse_click(8, 5);
}

void MainWindow::on_pushButton_79_clicked()
{
    Mouse_click(8, 6);
}

void MainWindow::on_pushButton_80_clicked()
{
    Mouse_click(8, 7);
}

void MainWindow::on_pushButton_81_clicked()
{
    Mouse_click(8, 8);
}

