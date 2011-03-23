#include "EasyBMP.h"

int array[3][3]={
{0,1,0,},
{1,0,1,},
{0,1,0,},
};
//����תͼ��
void array2bmp()
{
    int i,j;
    BMP bmp;
    RGBApixel pix_black={0};//R=0 G=0 B=0Ϊ��ɫ
    RGBApixel pix_white={255,255,255,0};//��ɫ

    bmp.SetSize(3,3);
    bmp.SetBitDepth(1);
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(array[i][j]==1)
            {
                bmp.SetPixel( i,  j,pix_black);
            }
            else
            {
                bmp.SetPixel( i,  j,pix_white);
            }
        }
    }

    bmp.WriteToFile("examp_array2bmp.bmp");
    printf("array2bmp suc...\n");
}

//ͼ��ת����
void bmp2array()
{
    int i,j;
    BMP bmp;
    int *pdata=NULL;
    int *phead=NULL;
    int *buf=NULL;
    int width;
    int height;

    bmp.ReadFromFile("examp_bmp2array.bmp");
    width = bmp.TellWidth();
    height= bmp.TellHeight();


    pdata=(int*)malloc(width*height*sizeof(int));
    phead = pdata;
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {//��ӡģ��ͼ,�հ�Ϊ'.',��ɫΪ'M'
            *pdata=bmp(j,i)->Red;//λ��1,��Red��������
            pdata++;
        }
    }
    //save
    pdata=phead;
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {//��ӡ���ն�
            printf("%d,",*pdata);
            pdata++;
        }
        printf("\n");
    }
    printf("bmp2array suc...\n");
    getchar();
}
int main()
{
    array2bmp();
    bmp2array();

    return 1;
}
