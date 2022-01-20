#include <bits/stdc++.h>
#include <fstream>

#define range_in_upperleft (y <= 2*x + 200)
#define range_in_lowerleft (y >= -1.87*x + 140)
#define range_in_lowerright (y >= 4.8*(x-75))
#define range_in_upperright (y <= -0.8*(x-150)+360)

#define in_taipei (pow((x-105),2)+pow((y-370),2))<=1225
#define in_taichung (pow((x-55),2)+pow((y-250),2))<=1225
#define in_gaoxiong (pow((x-45),2)+pow((y-120),2))<=1225

using namespace std;

float distance(float x1, float x2, float y1, float y2){
    float a = pow((x1-x2),2);
    float b = pow((y1-y2),2);
    float d = sqrt(a+b);
    return d;
}

int main(int argc, char* argv[]){
    string file_data, file_connect;
    int n = 100;
    if(argc>1){
        n = atoi(argv[1]);
    }
    file_data = argv[2];
    file_connect = argv[3];
    srand(time(NULL));
    float x,y;
    ofstream file;

    file.open(file_data, ios_base::app);
    int arr[n][4] = {0};

    for(int i=0;i<n;i++){
        x = rand()%151;
        y = rand()%401;
        if(range_in_upperleft && range_in_lowerleft && range_in_lowerright && range_in_upperright){
            if((in_taipei)||(in_taichung)||(in_gaoxiong)){
                file << i <<' '<<  x << ' ' << y << " 1" << endl;
                arr[i][0] = i; arr[i][1] = x; arr[i][2] = y; arr[i][3] = '1';
            }
            else{
                file << i <<' '<<  x << ' ' << y << " 2" << endl;
                arr[i][0] = i; arr[i][1] = x; arr[i][2] = y; arr[i][3] = '2';
            }
        }
        else{
            i--;
        }
    }
    file.close();

    file.open(file_connect, ios_base::app);
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            float d = distance(arr[i][1],arr[j][1],arr[i][2],arr[j][2]);
            if(i != j){
                if((arr[i][3]=='1' && arr[j][3]=='1')){
                    if(d <= 80){
                        file << i << ' ' << j << ' ' << d << endl;
                    }
                }
                else if((arr[i][3] == '2' && arr[j][3] == '1')||( arr[i][3] == '1' && arr[j][3] == '2')){
                    if(d <= 40){
                        file << i << ' ' << j << ' ' << d << endl;
                    }
                }
                else if(arr[i][3] == '2' && arr[j][3] == '2'){
                    if(d <= 30){
                        file << i << ' ' << j << ' ' << d << endl;
                    }
                }
            }
        }

    }

    file.close();

    return 0;
}
