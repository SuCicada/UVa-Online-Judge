//��������������¼��ǰ�������Ĵ�������ԭʼ�ַ��������ַ���
//1����Ϊ�ظ��²ⲻ������������Ƚ�guess�ַ����е��ظ��ַ���ȥ����ѭ����string::erase()
//2����ѭ���²��ַ�������ѭ��ԭʼ�ַ����������ͬ���ͽ�ԭʼ�ַ����Ĵ�Ԫ�ر�ɡ� * ����
//3��û����һ�ξͼ�¼����ѭ�������������¼�¼������win��lose��return����������ѭ��������֮���˵���ǡ���Ȩ����
#include<iostream>
#include<string>
using namespace std;
    string orig,guess;
int hang(int num,int right)
{
    for(int i=0;i<guess.size();i++)
    {
        int iff=0;
        for(int j=0;j<orig.size();j++)
        {
            if(orig[j]==guess[i])
            {
                orig[j]='*';
                iff=1;
                num--;
            }
            if(num==0)
            {
                cout<<"You win."<<endl;
                return 1;//break;
            }
        }
        if(iff==0)
        {
            right--;
        }
        if(right<0)
        {
            cout<<"You lose."<<endl;
            return -1;
        }
//        if(num==0)
//        {
//            cout<<"win"<<endl;
//            break;
//        }
    }
    cout<<"You chickened out."<<endl;
}
int main()
{
    int T;
    while(cin>>T&&T!=-1)
    {
        cin>>orig>>guess;
        for(int i=0;i<guess.size();i++)
        {
            for(int j=i+1;j<guess.size();j++)
            {
                if(guess[j]==guess[i])
                    guess.erase(guess.begin()+j);
            }
        }
        //cout<<guess<<endl;
        int right=6;//�������
        int num=orig.size();//Ҫ�µĸ���
        cout<<"Round "<<T<<endl;
        hang(num,right);
    }
    return 0;
}
//AC at 2018/2/7
