//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i]<< " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Gfg {
  public:
    map<string,int> mp;
    int k;
    Gfg(int gap){
        k=gap;
    }
    bool judgeOrNot(string &si) {
        string name;
        int time;
        for(int i=0;i<si.size();i++){
            if(si[i]=='@'){
                name=si.substr(0,i);
                time=timecal(si.substr(i+1,si.size()-i));
                break;
            }
        }
        if(mp.find(name)!=mp.end()){
            if(mp[name]>time) time+=86400;
            if((time - mp[name])>=k){
                mp[name]=time;
                return true;
            }
            else return false;
        }else{
            mp[name]=time;
            return true;
        }
    }
    int timecal(string t){
        long long h,m,s,i=0;

        h+=stoi(t.substr(i,2));
        m+=stoi(t.substr(i+3,2));
        s+=stoi(t.substr(i+6,2));

        return (h*60*60+m*60+s);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int gap;
        scanf("%d",&gap);
        
        
        vector<string> s(n);
        Array::input(s,n);
        
        Gfg obj(gap);
        for(int i=0;i<n;i++){
            bool res = obj.judgeOrNot(s[i]);
            if(res){
                cout<<"true ";
            }
            else{
                cout<<"false ";
            }
            
        }
        cout<<endl;
        
        
    }
}

// } Driver Code Ends