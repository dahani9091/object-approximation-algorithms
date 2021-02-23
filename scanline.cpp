

#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "scanline.h"




void scanline()
{
    int i;
    point p[20];
    int inter[20],x,y;
    int v,xmin,ymin,xmax,ymax, cl;

    printf("\n\t SCAN_FILL ALGORITHM");
    printf("\n Enter the no of vertices of polygon:");
    scanf("%d",&v);
    if(v>2)
    {
        for(i=0;i<v; i++) //ACCEPT THE VERTICES
        {
            printf("\nEnter the co-ordinate no.-%d: ",i+1);
            printf("\n\tx%d=",i+1);
            scanf("%d",&p[i].x);
            printf("\n\ty%d=",i+1);
            scanf("%d",&p[i].y);
        }
        p[i].x=p[0].x;
        p[i].y=p[0].y;
        xmin=xmax=p[0].x;
        ymin=ymax=p[0].y;
    }
    else
        printf("\n Enter valid no. of vertices.");

 //MAX,MIN
    for(int i=0;i<v;i++)
    {
        if(xmin>p[i].x)
        xmin=p[i].x;
        if(xmax<p[i].x)
        xmax=p[i].x;
        if(ymin>p[i].y)
        ymin=p[i].y;
        if(ymax<p[i].y)
        ymax=p[i].y;
    }

    cleardevice();
    printf("\n\tEnter the colour u want:(0-15)->"); //Selecting colour
    scanf("%d",&cl);
    setcolor(cl);

//DISPLAY FUNCTION
    int ch1;
    char ch='y';
    float s,s2;
    do
    {
        printf("\n\nMENU:");
        printf("\n\n\t1 . Scan line Fill ");
        printf("\n\n\t2 . Exit ");
        printf("\n\nEnter your choice:");
        scanf("%d",&ch1);
        switch(ch1)
        {
            case 1:
                s=ymin+0.01;
                delay(100);
                cleardevice();
                while(s<=ymax)
                {
                     int x1,x2,y1,y2,temp;
                     int c=0;
                     for(int i=0;i<v;i++)
                     {
                       x1=p[i].x;
                       y1=p[i].y;
                       x2=p[i+1].x;
                       y2=p[i+1].y;
                       if(y2<y1)
                        {
                          temp=x1;
                           x1=x2;
                           x2=temp;
                           temp=y1;
                           y1=y2;
                           y2=temp;
                        }
                        if(s<=y2&&s>=y1)
                        {
                          if((y1-y2)==0)
                            x=x1;
                          else // used to make changes in x. so that we can fill our polygon after cerain distance
                         {
                           x=((x2-x1)*(s-y1))/(y2-y1);
                           x=x+x1;
                          }
                          if(x<=xmax && x>=xmin)
                           inter[c++]=x;
                        }
                        }
                    int j,i;
                    for(i=0;i<v;i++)
                    {
                      line(p[i].x,p[i].y,p[i+1].x,p[i+1].y); // used to make hollow outlines of a polygon
                       }
                    delay(100);
                    for(i=0; i<c;i+=2)
                     {
                      delay(100);
                    line(inter[i],s,inter[i+1],s);  // Used to fill the polygon ....
                    }
                    s++;
                }
                break;
            case 2:
                exit(0);
        }

        printf("Do you want to continue?: ");
        scanf("%d",&ch);
    }while(ch=='y' || ch=='Y');
}


void main_scanline(GtkButton* btn, GtkWidget* win_menu) //START OF MAIN
{
    /// hide the menu window
    gtk_widget_hide(win_menu);
    initwindow(500,600);
    cleardevice();
    scanline();
    closegraph(); //CLOSE THE GRAPH
    getch();
}



