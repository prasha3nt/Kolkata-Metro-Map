#include<bits/stdc++.h>
#define TOTSTAT 36


using namespace std;

vector<int>parent(TOTSTAT,-1);

void LinkStations(vector<pair<int,int>> metroMap[], int stationCode1, int stationCode2, int dist)
{
    metroMap[stationCode1].push_back(make_pair(stationCode2,dist));
    metroMap[stationCode2].push_back(make_pair(stationCode1,dist));
}


int shortestPath(int source, int destination, vector<pair<int,int>>metroMap[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>DistfromS(TOTSTAT,INT_MAX);
        DistfromS[source]=0;
        pq.push(make_pair(0,source));
        

        while(!pq.empty())
        {
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto it:metroMap[node])
            {
                int mutual_dist=it.second;
                int next_station=it.first;

                if(dist+mutual_dist < DistfromS[next_station])
                {
                    DistfromS[next_station]=dist+mutual_dist;
                    pq.push(make_pair(DistfromS[next_station],next_station));
                    parent[next_station]=node;

                }
            }

        }
        float ans=DistfromS[destination];
        return ans;

    }

void showStation(int stationCode)
{
    if(stationCode==0) cout<<"Barrackpore";
    if(stationCode==1) cout<<"Tata Gate";
    if(stationCode==2) cout<<"Subhash Nagar";
    if(stationCode==3) cout<<"Baranagar";
    if(stationCode==4) cout<<"Dakshineswar";
    if(stationCode==5) cout<<"Noapara";
    if(stationCode==6) cout<<"Dumdum";
    if(stationCode==7) cout<<"M.G. Road";
    if(stationCode==8) cout<<"Central";
    if(stationCode==9) cout<<"Sealdah";
    if(stationCode==10) cout<<"Park Street";
    if(stationCode==11) cout<<"Rabindra Sadan";
    if(stationCode==12) cout<<"Netaji Bhawan";
    if(stationCode==13) cout<<"Kalighat";
    if(stationCode==14) cout<<"Dumdum Cantt.";
    if(stationCode==15) cout<<"Jessore Road";
    if(stationCode==16) cout<<"Biman Bandar";
    if(stationCode==17) cout<<"Howrah Maidan";
    if(stationCode==18) cout<<"Howrah";
    if(stationCode==19) cout<<"Phoolbagan";
    if(stationCode==20) cout<<"Saltlake Stadium";
    if(stationCode==21) cout<<"Central Park";
    if(stationCode==22) cout<<"Karunamoyee";
    if(stationCode==23) cout<<"Mominpur";
    if(stationCode==24) cout<<"Majerhat";
    if(stationCode==25) cout<<"Tartala";
    if(stationCode==26) cout<<"Behala Bazar";
    if(stationCode==27) cout<<"Shahid Khudiram";
    if(stationCode==28) cout<<"Kavi Subhash";
    if(stationCode==29) cout<<"Satyajeet Ray";
    if(stationCode==30) cout<<"VIP Bazar";
    if(stationCode==31) cout<<"Beliaghata";
    if(stationCode==32) cout<<"Nicco Park";
    if(stationCode==33) cout<<"Sector V";
    if(stationCode==34) cout<<"Technopolis";
    if(stationCode==35) cout<<"New Town";
}

void ShortestRoutePath(int destination)
{
    if(parent[destination]!=-1)
    {
        ShortestRoutePath(parent[destination]);
        showStation(parent[destination]);
        cout<<"-> ";
    }
}

int fareCal(int jourDist)
{
    if(jourDist<=2000) return 5;
    else if(jourDist>2000 && jourDist<=5000) return 10;
    else if(jourDist>5000 && jourDist<=10000) return 15;
    else if(jourDist>10000 && jourDist<=20000) return 20;
    else return 25;

}



int main()
{

    int source, destination;
    vector<pair<int,int>> metroMap[TOTSTAT];
    LinkStations(metroMap, 0, 1, 1900);
    LinkStations(metroMap, 1, 2, 3300);
    LinkStations(metroMap, 2, 3, 5800);
    LinkStations(metroMap, 3, 4, 1700);
    LinkStations(metroMap, 3, 5, 950);
    LinkStations(metroMap, 5, 14, 3900);
    LinkStations(metroMap, 14, 15, 2400);
    LinkStations(metroMap, 15, 16, 1400);
    LinkStations(metroMap, 5, 6, 1800);
    LinkStations(metroMap, 6, 7, 6900);
    LinkStations(metroMap, 7, 8, 950);
    LinkStations(metroMap, 8, 9, 1500);
    LinkStations(metroMap, 9, 18, 4500);
    LinkStations(metroMap, 18, 17, 1200);
    LinkStations(metroMap, 9, 19, 3000);
    LinkStations(metroMap, 19, 20, 1700);
    LinkStations(metroMap, 20, 21, 2800);
    LinkStations(metroMap, 21, 22, 850);
    LinkStations(metroMap, 22, 33, 1200);
    LinkStations(metroMap, 33, 34, 1100);
    LinkStations(metroMap, 34, 35, 5800);
    LinkStations(metroMap, 33, 32, 1600);
    LinkStations(metroMap, 32, 31, 3100);
    LinkStations(metroMap, 31, 30, 3100);
    LinkStations(metroMap, 30, 29, 4800);
    LinkStations(metroMap, 29, 28, 2200);
    LinkStations(metroMap, 28, 27, 2400);
    LinkStations(metroMap, 27, 13, 8900);
    LinkStations(metroMap, 13, 12, 1800);
    LinkStations(metroMap, 12, 11, 700);
    LinkStations(metroMap, 11, 10, 1700);
    LinkStations(metroMap, 10,  9, 3100);
    LinkStations(metroMap, 10, 23, 4500);
    LinkStations(metroMap, 23, 24, 1600);
    LinkStations(metroMap, 24, 25, 2000);
    LinkStations(metroMap, 25, 26, 1000);



    cout<<"\t\tWelcome!!!  This application will help you find Shortest Route Map"<<endl;
    cout<<"\t\tfrom Source Station to Destination Station. It will also calculate"<<endl;
    cout<<"\t\tdistance and fare for you!!!\n\n"<<endl;

    cout<<"\t\tFollowing are the Station Codes for each station. You have to enter"<<endl;
    cout<<"\t\trespective Station Code for each Station."<<endl<<endl;
    cout<<"\t\tBarrackpore:     0\tNetaji Bhawan:    12\tMajerhat:        24"<<endl;
    cout<<"\t\tTata Gate:       1\tKalighat:         13\tTartala:         25"<<endl;
    cout<<"\t\tSubhash Nagar:   2\tDumdum Cantt:     14\tBehala Bazar:    26"<<endl;
    cout<<"\t\tBaranagar:       3\tJessore Road:     15\tShahid Khudiram: 27"<<endl;
    cout<<"\t\tDakshineshwar:   4\tBiman Bandar:     16\tKavi Subash:     28"<<endl;
    cout<<"\t\tNoapara:         5\tHowrah Maidan:    17\tSatyajeet Ray:   29"<<endl;
    cout<<"\t\tDumdum:          6\tHowrah:           18\tVIP Bazar:       30"<<endl;
    cout<<"\t\tM.G. Road:       7\tPhoolbagan:       19\tBeliaghata:      31"<<endl;
    cout<<"\t\tCentral:         8\tSaltlake Stadium: 20\tNicco Park:      32"<<endl;
    cout<<"\t\tSealdah:         9\tCentral Park:     21\tSector V:        33"<<endl;
    cout<<"\t\tPark Street:    10\tKarunamoyee:      22\tTechnopolis:     34"<<endl;
    cout<<"\t\tRabindra Sadan: 11\tMominpur:         23\tNew Town:        35"<<endl;

    cout<<"\n\t\tPlease Enter the Source Staion code: ";
    cin>>source;
    cout<<"\t\tPlease Enter the Destination Station code: ";
    cin>>destination;
    int jourDist=shortestPath(source,destination, metroMap);
    float inKM= (float) jourDist/1000;

    cout<<"\n\t\tThe shortest route from ";
    showStation(source);
    cout<<" to ";
    showStation(destination);
    cout<<" is through: ";
    cout<<endl;
    cout<<"\t\t";
    ShortestRoutePath(destination);
    showStation(destination);
    cout<<endl;
    cout<<"\n\t\tThe distance of the above journey will be "<<inKM<<" KM.";
    cout<<"\n\t\tAnd the above journey would cost Rs."<<fareCal(jourDist);
    cout<<endl<<endl;

    cout<<"\t\tpress any key to exit: ";
    int t;
    cin>>t;
    return 0;
}
