/*
ccc96s4
ac, there are issues with the problem statement and whitespace requirements.
overall a fairly simple implementation problem, just takes some time to type up
*/
//the glory of rome is eternal
#include <cstdio>
#include <string> 
#include <iostream>

using namespace std; 
//remembered you could sum strings halfway through.......... BRUH BRUH BURH
int convertdec(string num){
    int ind = 0, ans = 0; 
    for(ind = 0; ind < num.length(); ind++){
        if(num[ind] == 'I'){
            if(ind + 1 == num.length()) ans++; 
            //else if(ind > 0 && num[ind-1] == 'I') ans++;
            else{
                if(num[ind+1] == 'X' || num[ind + 1] == 'V'){
                    ans-=1; 
                }
                else ans++; 
            }
        }

        if(num[ind] == 'V') ans+= 5; 
        if(num[ind] == 'X'){
            if(ind + 1 == num.length()) ans+=10; 
            //else if(ind > 0 && num[ind-1] == 'X') ans++;

            else{
                if(num[ind+1] == 'L' || num[ind + 1] == 'C'){
                    ans-=10; 
                }
                else ans+=10; 
            }
        }
        if(num[ind] == 'L') ans+= 50; 
        if(num[ind] == 'C'){
            if(ind + 1 == num.length()) ans+=100; 
            //else if(ind > 0 && num[ind-1] == 'C') ans++;
            else{
                if(num[ind+1] == 'D' || num[ind + 1] == 'M'){
                    ans-=100; 
                }
                else ans+=100; 
            }
        }
        if(num[ind] == 'D') ans+= 500; 
        if(num[ind] == 'M') ans+= 1000; 
    }
    return ans; 
}

string convertrom(int num){
    string ans; 
    while(num){
        if(num >= 1000){ ans.push_back('M'); num-=1000;}
        else if(num >= 900){ans.push_back('C'); ans.push_back('M'); num-=900;}
        else if(num >= 500){ans.push_back('D'); num-=500;}
        else if(num >= 400){ans.push_back('C'); ans.push_back('D'); num-=400;}
        else if(num >= 100){ans.push_back('C'); num-=100;}
        else if(num >= 90){ans+= "XC"; num-= 90;}
        else if(num >= 50){ans+= 'L'; num-=50;}
        else if(num >= 40){ans+= "XL"; num-= 40;}
        else if(num >= 10){ans+= 'X'; num-=10;}
        else if(num >= 9){ans+= "IX"; num-=9;}
        else if(num >= 5){ans +='V'; num -= 5;}
        else if(num >=4){ans += "IV"; num-=5;}
        else if(num >= 1){ans += 'I'; num--;}
    }
    return ans;
}

int main(){
    int tc; scanf("%d\n", &tc); 
    while(tc--){
        string line; 
        getline(cin, line); 
        string _a, _b; 
        int i = 0; 
        for(i; i < line.length(); i++){
            if(line[i] == '+') break; 
            else _a.push_back(line[i]); 
        }
        for(i; i< line.length(); i++){
            if(line[i]=='=') break; 
            else _b.push_back(line[i]); 
        }

        int a = convertdec(_a), b = convertdec(_b); 
        //printf("%d + %d = %d\n", a, b, a+b);
        printf("%s", line.c_str());
        if(a+b > 1000) printf("CONCORDIA CUM VERITATE\n"); 
        else printf("%s\n",convertrom(a+b).c_str());
        //if(tc)printf("\n");
    }
    return 0;
}