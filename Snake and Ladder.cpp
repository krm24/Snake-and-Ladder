// Author : Koumudi Ranjan Mandal
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define INF  INT_MAX
#define LINF LLONG_MAX
#define F first
#define S second
#define ld long double
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pii>
#define f(i,n) for(int i=0;i<n;i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define o4(a,b,c,d) fout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl;
#define initial(arr,val) memset(arr,val,sizeof(arr))
#define value(x) fout << #x << " is " << x << endl;
#define all(v) v.begin(), v.end()
#define yes fout<<"Yes"<<endl
#define no fout<<"No"<<endl
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int dx[8]={1,-1,0,0,-1,-1,1,1};
int dy[8]={0,0,-1,1,-1,1,-1,1};
int myrandom (int i) { 
    return std::rand()%i;}
void dice(int a,ostream& fout)
{
if(a==1)
{
fout << " ----- " << endl;
fout << "|     |" << endl;
fout << "|  O  |" << endl;
fout << "|     |" << endl;
fout <<  " -----" << endl;
}
else if(a==2)
{
fout << " -----" << endl;
fout << "|    O|" << endl;
fout << "|     |" << endl;
fout << "|O    |" << endl;
fout <<  " -----" << endl;
}
else if(a==3)
{
fout << " -----" << endl;
fout << "|    O|" << endl;
fout << "|  O  |" << endl;
fout << "|O    |" << endl;
fout <<  " -----" << endl;
}
else if(a==4)
{
fout << " -----" << endl;
fout << "|O   O|" << endl;
fout << "|     |" << endl;
fout << "|O   O|" << endl;
fout <<  " -----" << endl;
}
else if(a==5)
{
fout << " -----" << endl;
fout << "|O   O|" << endl;
fout << "|  O  |" << endl;
fout << "|O   O|" << endl;
fout <<  " -----" << endl;
}
else if(a==6)
{
fout << " -----" << endl;
fout << "|O   O|" << endl;
fout << "|O   O|" << endl;
fout << "|O   O|" << endl;
fout <<  "-----" << endl;
}
}
int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    map<int,int> s,l;
    int a=0;
    fin>>a;  // number of snakes
    f(i,a)
    {
        int b,c;
        fin>>b>>c; // position of snake
        s.insert({b,c}); // inserting in map : - head as key and tail as value
    }
    int al=0;
    fin>>al;  // number of ladders
    f(i,al)
    {
        int b,c;
        fin>>b>>c; // position of ladders
        l.insert({b,c}); // inserting in map :- lower end as key and upper end as value
    }
    int n=1; 
    fin>>n;  // number of players
    vector<string> p(n);
    f(i,n){ // if names are not entered
        p[i]="Player "+to_string(i+1); 
    }
    f(i,n)
    {
        fin>>p[i]; // name of players are pushed in vector
    }
    vector<int> v(n,0); // vector for current position of every player and is initialized to zero
    uniform_int_distribution <int> dis(1,6); // dice can take values from 1 to 6 . so using uniform distribution with random number generator mt19937
    while(1)
    {
        for(int i=0;i<n;i++)
        {
            int num=dis(rng); // generating a random number between 1 to 6
            fout<<p[i]<<" Rolled Dice :"<<endl;
            dice(num,fout);
            int ini=v[i];     // initial value of the player's postion
            int ch=num;
            num+=v[i];
            bool ok=true;
            if(num>100)  // no moves , program will jump to printing the statements
            {
                ok=false;
                num=v[i];
            }
            while(ok)
            {
                ok=false;
                if(s.find(num)!=s.end()) // finding if there is a snake at the postion which has been obtained by rolling the dice
                {
                    ok=true;
                    num=s[num]; // if its true , we make the postion of player as the tail of the snake
                }
                if(l.find(num)!=l.end()) // finding if there is a ladder at the postion which has been obtained by rolling the dice
                {
                    ok=true;
                    num=l[num];  // if its true , we make the postion of player as the upper end of the ladder
                }
                // since there can be cases where one player rolled a dice and got a snake and when he/she arrived at new postion arrrived, there is ladder/snake .so we run the loop till we are geeting a laader or snake.
            }
            fout<<p[i]<<" rolled a "<<ch<<" and moved from "<<ini<<" to "<<num<<endl;
            if(num==100)
            {   
                fout<<"\t\t============================="<<endl;
                fout<<"\t\t||       GAME OVER!!!      ||"<<endl;
                fout<<"\t\t============================="<<endl;
                fout<<p[i]<<" wins the game"<<endl; // game ends when someonr reaches 100.
                return 0;
            }
            v[i]=num; // updating the position of the current player after all the moves :D
        }
    }
}