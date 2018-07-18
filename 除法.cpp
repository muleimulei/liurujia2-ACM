#include<cstdio> 
#include<vector>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<sstream>
using namespace std;


int main(){
//	freopen("1.txt", "w+", stdout);
	int num;
	while(scanf("%d", &num)==1 && num ){
		
		string s="";
		int f = 0;
		for(int n1 = 0; n1<10; n1++){
			s += to_string(n1);
			
			for(int n2 = 0; n2<10; n2++){
				if(n2 != n1){
					s+=to_string(n2);
					
					for(int n3 = 0; n3 < 10; n3++){
						if(n3!=n1 && n3 != n2){
							s+=to_string(n3);
							
							for(int n4 = 0; n4 < 10; n4++){
								if(n4!= n1 && n4 != n2 && n4 != n3){
									s+= to_string(n4);
									
									for(int n5 = 0; n5<10; n5++){
										if(n5!= n1 && n5 != n2 && n5 != n3 && n5 != n4){
//											printf("%d %d %d %d %d\n", n1, n2, n3, n4 , n5);
											s+= to_string(n5);
											
											int v1 = atoi(s.c_str());
//											printf("%d\n", v1);
											
											int v2 = v1 * num;
											string s2 = to_string(v2);
											if(s2.size()==4) s2 = '0' + s2;
											
											string d = s + s2;
											if(d.size()>10){
												goto go;
											}else{
												sort(d.begin(), d.end());
												if(d == "0123456789") {
													f = 1;
													printf("%s / %s = %d\n", s2.c_str(), s.c_str(), num);
												}
											}
										
											s.resize(4);
										}
									}
									s.resize(3);
								}
							}
							s.resize(2);
						}
					}
					s.resize(1);
				}
			}
			s.resize(0);
		}
		
		go: if(!f){
			printf("There are no solutions for %d.\n", num);
		}
		printf("\n");
	}
	return 0;
} 
