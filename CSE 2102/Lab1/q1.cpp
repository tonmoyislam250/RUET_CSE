#include<iostream>
using namespace std;

bool implier(bool p, bool q)
{
    if(p==true && q==false)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{
    // cout<<implier(1,0)<<endl;
    bool pi[2]={true,false};
    bool qi[2]={true,false};
    bool re=true;
    cout<<"P  Q  !p^(p->q)  pv(!q->p)"<<endl;
    for(auto i:pi)
    {
        for(auto j:qi)
        {
            cout<<i<<"  "<<j<<"     ";
            bool r,w,Y=implier(i,j);
            r=((!i)&&Y);
            w=(i||implier(!j,i));
            //r=!(i||j);
            //w=(!i)&&(!j);
            if(r!=w)
                re=false;
            cout<<r<<"      "<<w<<endl;
        }
    }
    if(re==false)
        cout<<"Those are not Equivalent"<<endl;
    else
         cout<<"Those are equivalent"<<endl;
}