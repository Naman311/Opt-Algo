#include<bits/stdc++.h>

using namespace std;

int main ()
{
    stack<char> st;
    string s,ans;
    cin>>s;
    s.insert(0,"(");
    s.push_back(')');
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>=65 && s[i]<=90)
        {
            ans.push_back(s[i]);
        }
        else
        {
            switch(s[i])
            {
                case '(':
                       st.push(s[i]);
                       break;
                case ')':
                        while(st.top()!='(')
                        {
                            ans.push_back(st.top());
                            st.pop();
                        }
                        st.pop();
                        break;
                case '^':
                        st.push(s[i]);
                        break;
                case '*':
                case '/':
                        while(st.top()=='^' && st.top()!='(')
                        {
                            ans.push_back(st.top());
                            st.pop();
                        }
                        st.push(s[i]);
                        break;
                case '+':
                case '-':
                        while((st.top()=='/'|| st.top()=='*') && st.top()!='(')
                        {
                            ans.push_back(st.top());
                            st.pop();
                        }
                        st.push(s[i]);
                        break;
                default:cout<<"Wrong input";
            }
        }
    }
    cout<<ans;
    return 0;
}
