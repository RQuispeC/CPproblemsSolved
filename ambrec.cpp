//https://books.google.com.pe/books?id=yG6qJBAnE9UC&lpg=PA195&ots=rsZLO1cZgQ&dq=primero%20y%20siguiente%20compiladores&hl=es&pg=PA194#v=onepage&q=primero%20y%20siguiente%20compiladores&f=false
//http://myslide.es/documents/analizadorsintactico.html
#include<bits/stdc++.h>
#define	INF 1e9
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define MAX 105
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long int64;
typedef pair< int64, int64 > pll;
typedef pair < string, string> pss;
typedef vector < string > vs; 
map < string , vs > reglas, reglasTmp, casoBaseRec, casoRecRec, followGraph;
map < string , set < string > > FIRST, FOLLOW;
map < string, bool > isTerminal, vis, derivanEPS;
vs v;
set < string > TERMINAL, NOTERMINAL, NULABLE, dicc;
string LLK[MAX][MAX], begString;
/*reglas de a forma  X = Xr*/
pss getRule(string x)
{
    int pos=0;
    for(pos=0;pos<x.size();pos++)
        if(x[pos] == '=' ) break;
    string s1 = x.substr(0, pos);
    string s2 = x.substr(pos+1, x.size() - pos);
    return pss(s1,s2);
}
string fString(string x)
{
    if(x=="Є" || x=="$" || x=="") return x;
    if(x.size()<=1) return x;
    int pos=1, ok=0;
    while(x[pos]==39)
    {
        pos++;
        ok=1;
    }
    if(ok) return x.substr(0, pos+1);
    string ans="";
    foreach(dicc, it)
    {
        string auxc = *it;
        if(auxc.size() > x.size()) continue;
        if(x.substr(0,auxc.size()) == auxc) 
        {
            if(auxc.size()>ans.size())
            ans = *it;
        }    
    }
    if(ans!="") return ans;
    return x.substr(0, 1);
}
bool  matchTerminal(string x)
{
    if(x=="Є" || x == "$") return 1;
    for(int i=0;i<x.size();i++)
        if(x[i]<='Z' && x[i]>='A')
            return 0;
    return 1;
}
string fLess(string x)
{
    
    string ans = x.substr(fString(x).size(), x.size() - fString(x).size());
    if(ans=="") ans ="Є";
    return ans;
}
string fLess2(string x)
{
    
    string ans = x.substr(fString(x).size(), x.size() - fString(x).size());
    return ans;
}
bool existeRecursividad()
{
    reglasTmp.clear();
    casoBaseRec.clear();
    casoRecRec.clear();
    bool exists =0;
    foreach(reglas,it)
    {
        string left = it->first;
        bool ok = 1;
        for(int  i=0;i< (it->second).size();i++)
        {
            string right  = (it->second)[i];
            if( left.size() <= right.size() && left == right.substr(0, left.size()))
            {
                exists = 1;
                ok = 0;
                casoRecRec[left].push_back(right.substr(left.size(), (int)left.size() - (int)right.size()));
            }
            else
            {
                casoBaseRec[left].push_back(right);
            } 
        }
        if(ok) continue;
        (it->second).clear();
        vs tmpv = vs(casoBaseRec[left].begin(), casoBaseRec[left].end());
        for(int i=0;i<tmpv.size();i++)
        {
            (it->second).push_back(tmpv[i]+left + "'");
            isTerminal[tmpv[i]+left + "'"] = matchTerminal(tmpv[i]+left + "'");
            /*if(dicc.size())
            {
                dicc.insert(tmpv[i]+left + "'");
            }*/
        }    
        tmpv = vs(casoRecRec[left].begin(), casoRecRec[left].end());
        bool needed = 1;
        for(int i=0;i<tmpv.size();i++)
        {
            if(tmpv[i]=="")
            {
                reglas[left + "'"].push_back("Є");
                if(dicc.size())
                {
                    dicc.insert(left + "'");
                    dicc.insert("Є");
                }
                bool needed = 0;    
                continue;
            }
            reglas[left + "'"].push_back(tmpv[i]  + left + "'");
            isTerminal[tmpv[i]  + left + "'"] = matchTerminal(tmpv[i]  + left + "'");
            if(dicc.size())
            {
                dicc.insert(left + "'");
                
                
            }
        }   
        if(needed)
            reglas[left + "'"].push_back("Є");
    }
    foreach(reglas,it)
        sort((it->second).begin(), (it->second).end());
    return exists;
}
bool existeAmbiguedad()
{
    reglasTmp.clear();
    casoBaseRec.clear();
    casoRecRec.clear();
    bool exists =0;
    int inic = reglas.size();
    foreach(reglas,it)
    {
        sort((it->second).begin(), (it->second).end());
        vs tmpv = vs(reglas[it->first].begin(), reglas[it->first].end());       
        int i=0;
        while(i<tmpv.size())
        {
            int j=i+1;
            while(j<tmpv.size() && fString(tmpv[i])==fString(tmpv[j]))
            {
                //cout<<fString(tmpv[i])<<" ** "<<fString(tmpv[j])<<endl;
                j++;
            }    
            //cout<<i<<" : "<<j<<endl;
            if(i+1==j) i++;
            else
            {
                (it->second).clear();
                for(int k=0;k<i;k++)
                {
                    (it->second).push_back(tmpv[k]);
                    //cout<<"en1 "<<tmpv[k]<<endl;
                 }   
                for(int k=j;k<tmpv.size();k++)
                {
                    (it->second).push_back(tmpv[k]);
                   // cout<<"en2 "<<tmpv[k]<<endl;    
                }    
                (it->second).push_back(fString(tmpv[i])+(it->first)+"'");
                //cout<<"en3 "<< fString(tmpv[i])+(it->first)+"'" <<endl;
                bool hasEmpty = 0 ;
                for(int k=i;k<j;k++)
                {
                    string in = fLess(tmpv[k]);
                    if(in=="Є" && hasEmpty)  continue;
                    if(in=="Є") hasEmpty=1;
                    reglas[(it->first)+"'"].push_back(in);
                    //cout<<(it->first)+"'"<<" : "<<in<<endl;
                    if(dicc.size())
                    {
                        dicc.insert( (it->first)+"'" );
                    }
                }
                exists = 1;
                //cout<<(it->first)<<" : "<<(it->first).size()<<endl;
                i=tmpv.size();
            }
        }
    }
    return exists;
}

void getDerivanEPS()
{
    derivanEPS.clear();
    foreach(reglas,it)
    {
        bool ok = 0;
        for(int i=0;i<(it->second).size();i++)
            if((it->second)[i]=="Є") 
            {
                ok = 1;
                break;
            }
        derivanEPS[it->first]=ok;
    }
}
// -----------sacar el primero (X)----------------------------
set < string > first;
string beg;
void getFirst(string x, bool empty, string root, bool isFirstRule, string firstRule)
{
    vis[x] = 1;
    if(reglas.find(x) == reglas.end()) goto totem;
    else{
    vs tmpv = vs(reglas[x].begin(), reglas[x].end());
    for(int i=0; i < tmpv.size();i++)
    {
        if(tmpv[i]=="Є")
        {
            first.insert("Є");
            continue;
        }
        if(!vis[fString(tmpv[i])] )
        {
            if(isFirstRule)
                getFirst(fString(tmpv[i]), fString(tmpv[i]).size() > 1, root, 0, tmpv[i]);
            else
                getFirst(fString(tmpv[i]), fString(tmpv[i]).size() > 1, root, 0, firstRule);
        }    
    }
    }
totem:
    if(firstRule=="") return ;
    if(matchTerminal(fString(x)) || matchTerminal(x))
    {
        string ans;
        if(empty) ans = "Є";
        else ans = x;
        first.insert(ans);
        
        if(!empty)
        {
            
            int posNT = distance(NOTERMINAL.begin(), NOTERMINAL.find(root));
            int posT = distance(TERMINAL.begin(), TERMINAL.find(x));
            if(NOTERMINAL.find(root)==NOTERMINAL.end()) cout<<"asdddddasdasdasdasdasdasdasd "<< root<<" : "<< firstRule <<" --> "<<root<<endl;
            if(TERMINAL.find(root)==TERMINAL.end()) cout<<"asdddddasdasdasdasdasdasdasd "<< root<<" : "<<firstRule <<" --> "<<root<<endl;
            LLK[posNT][posT] = firstRule;
        }
    } 
}
void getAllFirst()
{
    set < string > terminals;
    foreach(reglas,it)
    {
        if(terminals.find(it->first)!=terminals.end()) continue;
        if(matchTerminal(it->first) && it->first!="$" && it->first!= "Є") 
        {
            terminals.insert(it->first);
            cout<<"first( "<< it->first << " ) = { "<< it->first <<" };"<<endl;
            FIRST[ it->first ].insert( it->first );
        }   
        for(int i=0;i<(it->second).size() ; i++)
        {
            string tmp = (it->second)[i];
            while(tmp.size())
            {
            
                string tmpv = fString(tmp);
                //cout<<tmp<<" --> "<<tmpv<<" --> "<<fLess2(tmp)<<endl;
                tmp = fLess2(tmp);
                if(terminals.find(tmpv)!=terminals.end()) continue;
                if(matchTerminal(tmpv) && tmpv!="$" && tmpv!= "Є") 
                {
                    terminals.insert(tmpv);
                    cout<<"first( "<< tmpv << " ) = { "<< tmpv <<" };"<<endl;
                    FIRST[ tmpv ].insert( tmpv );
                }    
                
            }
        }    
    }
    //cout<<terminals.size()<<endl;
    getDerivanEPS();
    foreach(reglas,it)
    {
        vis.clear();
        first.clear();
        beg=it->first;
        if(terminals.find(beg)  != terminals.end()) continue;
        getFirst(it->first, 0, it->first, 1, "");
        cout<<"first( "<< it->first << " ) = { ";
        int aux=0;
        foreach(first, itt)
        {
            cout<< *itt;
            if(aux+1<first.size()) cout<<", ";
            aux++;
            FIRST[ it->first ].insert( *itt);
        }
        cout<<" };"<<endl;
    }
    first.clear();
}
// ------ sacar el siguiente (X) --------------------------------
set < string > follow;
map < string , set < string > > rem;
void getFollow(string x)
{
    for(int i=0; i<followGraph[x].size();i++)
    {
        foreach(FIRST[followGraph[x][i]], it)
            if(*it != "Є")
                follow.insert(*it);
    }    
}
void getAllFollow()
{    
    FOLLOW.clear();
    rem.clear();
    followGraph.clear();
    map < string, bool > hasEmpty;
    hasEmpty.clear();
    set < string > notTerminal;
    foreach(reglas,it)
    {   
        if(!matchTerminal(it->first) && it->first!="$" && it->first!= "Є") 
        {
            notTerminal.insert(it->first);
        }
        for(int i=0;i<(it->second).size() ; i++)
        {
            string tmp = (it->second)[i];
            while(tmp.size())
            {            
                string tmpv = fString(tmp);
                tmp = fLess2(tmp);
                if(!matchTerminal(tmpv) && tmpv!="$" && tmpv!= "Є") 
                {
                    string tmpvv = fString(tmp);
                    //if(tmpvv=="" && FIRST[it->first].find("Є") != FIRST[it->first].end() && it->first != tmpv) 
                    if(tmpvv=="" && it->first != tmpv) 
                    {
                        rem[tmpv].insert(it->first); //add follow of it->first
                        //cout<<tmpv <<" --------> "<< it->first<<endl;
                        notTerminal.insert(tmpv);
                        hasEmpty[tmpv] = 1;
                        continue;
                    }
                    if(FIRST[tmpvv].find("Є") != FIRST[tmpvv].end() && tmpvv != tmpv)
                    {
                        rem[tmpv].insert(tmpvv); // add follow of tmpvv
                        //cout<<tmpv <<" ---**--> "<< tmpvv<<endl;
                    }
                    followGraph[tmpv].push_back(tmpvv);
                    notTerminal.insert(tmpv);
                }
            }
        }    
    }
   while(notTerminal.size())
    {
        foreach(notTerminal, it)
        {
            //cout<<"--> "<< *it << notTerminal.size() <<endl;
            bool ok=1;
            foreach(rem[*it], itt)
            {
               // cout<< *it <<" : "<< FOLLOW[*itt].size() <<endl;
                if(!FOLLOW[*itt].size()) ok=0;
            }    
            if(!ok) continue;
            //cout<<"paso!!"<<endl;
            vis.clear();
            follow.clear();
            getFollow(*it);
            //add follow of follow
            foreach(rem[*it], itt)
                foreach(FOLLOW[*itt], ittt)
                    FOLLOW[*it].insert(*ittt);   
            
            if((!followGraph[*it].size() || !follow.size()) && !FOLLOW[*it].size())
            {
                 //cout<< "follow ( "<< *it << " ) = { $ }"<<endl;
                 FOLLOW[*it].insert("$");
                 notTerminal.erase(*it);
                 continue;
            }
            //cout<<"follow ( "<< *it << " ) = { ";
            int aux=0;
            foreach(follow, itt)
            {
               // cout<< *itt;
                if(aux+1<follow.size()) cout<<", ";
                //aux++;
                FOLLOW[*it].insert(*itt);
            }
            //cout<<" };"<<endl;
            //cout<<notTerminal.size()<<endl;
            notTerminal.erase(*it);
            //cout<<notTerminal.size()<<endl;
            break;
        }
    }
    foreach(FOLLOW, it)
    {
        cout<<"follow ( "<< it->first << " ) = { ";
        int aux=0;
        foreach(it->second, itt)
        {
            cout<< *itt;
            if(aux+1<(it->second).size()) cout<<", ";
            aux++;
        }
        cout<<" };"<<endl;    
    }
    followGraph.clear();
    follow.clear();    
}
//-------------get NULABLE-----------------
bool matchNulable(string x)
{
    if(x=="Є") return 1;
    vis[x] = 1;
    bool ans = 0;
    if(reglas.find(x)==reglas.end()) return 0;
    vs tmpv = vs(reglas[x].begin(), reglas[x].end());
    for(int i=0;i<tmpv.size();i++)
    {
        if(!vis[tmpv[i]])
            ans |= matchNulable(tmpv[i]);
    }
    return ans;        
}
void getNulables()
{
    NULABLE.clear();
    foreach(NOTERMINAL, it)
    {
        vis.clear();
        if(matchNulable(*it))
        {
            NULABLE.insert(*it);
            //cout<< *it <<endl;
        }    
    }
}
//------------get TERMINAL Y NO TERMINAL VECTORS
void getTypeData()
{
    TERMINAL.clear();
    NOTERMINAL.clear();
    foreach(reglas, it)
    {
        if(matchTerminal(it->first))
            TERMINAL.insert(it->first);
        else
            NOTERMINAL.insert(it->first);
            
        //cout<< it->first << " * "<< matchTerminal(it->first)<<endl; 
        
        for(int i=0;i<(it->second).size() ; i++)
        {
            string tmp = (it->second)[i];
            while(tmp.size())
            {            
                string tmpv = fString(tmp);
                //cout<< ">>>> "<<tmpv<<endl;
                tmp = fLess2(tmp);
                if(tmpv=="$" || tmpv== "Є") continue;
                if(matchTerminal(tmpv)) 
                    TERMINAL.insert(tmpv);
                else
                    NOTERMINAL.insert(tmpv);     
            }
        } 
    }
    TERMINAL.insert("$");
    for(int i=0;i<NOTERMINAL.size();i++)
        for(int j=0;j<TERMINAL.size();j++)
            LLK[i][j]="error";  
}
void showLLKTable()
{
    foreach(TERMINAL, it)
        cout<<"terminal : "<<*it<<endl;
    foreach(NOTERMINAL, it)
        cout<<"no terminal : "<<*it<<endl;
    for(int i=0;i<NOTERMINAL.size();i++)
    {
        for(int j=0;j<TERMINAL.size();j++)
            cout<<LLK[i][j]<<"    ";
        cout<<endl;    
    } 
           
}
void completeLLKforNulable()
{
    foreach(NULABLE, it)
    {
        int posNT = distance(NOTERMINAL.begin(), NOTERMINAL.find(*it));
        //cout<<" null : "<< *it <<endl;
        foreach(FOLLOW[*it], itt)
        {            
            int posT = distance(TERMINAL.begin(), TERMINAL.find(*itt));
            //cout<< *itt << " >> "<< posT <<endl;
            if(LLK[posNT][posT] == "error")
                LLK[posNT][posT] = "Є";
        }
    }
}
bool matchSintaxis(string left, string right)
{
    //cout<<left <<"  :::  "<<right<<endl;
    if(left=="$" && right=="$") return 1;
    string fLeft = fString(left);
    string fRight = fString(right);
    if(fLeft == fRight)
        return matchSintaxis(fLess(left), fLess(right));
    if(TERMINAL.find(fLeft)!=TERMINAL.end() && TERMINAL.find(fRight)!=TERMINAL.end())
        return 0;
    if(NOTERMINAL.find(fLeft)!=NOTERMINAL.end() && NOTERMINAL.find(fRight)!=NOTERMINAL.end())
        return 0;
    if(TERMINAL.find(fLeft)!=TERMINAL.end()) return 0; 
    if(NOTERMINAL.find(fRight)!=NOTERMINAL.end()) return 0; 
    int posi, posj;
    posi = distance(NOTERMINAL.begin(), NOTERMINAL.find(fLeft));
    /*if(NOTERMINAL.find(fRight) != NOTERMINAL.end())
        posj = distance(NOTERMINAL.begin(), NOTERMINAL.find(fRight));
    else*/
        posj = distance(TERMINAL.begin(), TERMINAL.find(fRight));    
    if(LLK[posi][posj]=="error") return 0;
    return matchSintaxis( LLK[posi][posj] + fLess(left), right);
}
string evalSintaxis(string x)
{
    if(matchSintaxis(begString, x))
        return "Analisis sintaxtico exitoso";
    else    
        return "ERROR DE COMPILACION";
}
void showDiccionary()
{
    cout<<"Diccionario :"<<endl;
    foreach(dicc, it)
        cout<< *it <<endl;
}
int main()
{
    dicc.clear();
    FIRST.clear(), FOLLOW.clear();
    isTerminal.clear();    
    v.clear();    
    reglas.clear();
    string tmp; bool isfirst = 1;
    while(cin>>tmp)
    {
        if(tmp=="--------------") break;
        if(tmp.substr(0, 3)=="-->")
        {
            dicc.insert(tmp.substr(3, tmp.size() - 3));
            cout<< tmp.substr(3, tmp.size() - 3) <<endl;
            continue;
        }
        pss regla = getRule(tmp);
        if(isfirst) begString  = regla.first, isfirst = 0;
        isTerminal[regla.first] = matchTerminal(regla.first);
        isTerminal[regla.second] = matchTerminal(regla.second);
        if(!reglas[regla.first].size()) v.push_back(regla.first);
        reglas[regla.first].push_back(regla.second);
    }
    while(1)
    {
        int ok = 0;
        if(!existeRecursividad()) ok++;
        if(!existeAmbiguedad()) ok++;
        if(ok==2) break;
    }
    foreach (reglas, it)
    {
        if((it->second).size()) cout<< it->first <<" = ";
        for(int  i=0;i< (it->second).size();i++)
        {
            cout<< (it->second)[i];
            if(i+1 < (it->second).size()) 
                cout<<" | ";
        }    
        cout<<endl;
    }
    cout<<"--------------"<<endl;
    getTypeData();
    getNulables();
    getAllFirst();
    getAllFollow(); 
    completeLLKforNulable();
    
    showLLKTable();
    
    //showDiccionary();
    
    begString+="$";
    puts("Ingrese # de cadenas a evaluar");
    int nucad;
    scanf("%d", &nucad);
    while(nucad--)
    {
        string cad;
        cin>>cad;
        if(cad[cad.size()-1]!= '$') cad +="$";
        cout<<cad<<" : "<<evalSintaxis(cad)<<endl;
    }
}

