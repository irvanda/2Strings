#include <iostream>
#include <string>

using namespace std;

/* given 2 strings s1 and s2. Find the longest common subsequent from the given 2 strings. ex:
"ABCDA" and "MALBQDZ" = "ABD"
"ABBTGGA" and "BMTGXA" = "BTGA" 

logic:
- CHECK from S1, result1
- CHECK from S2, result2
- if result1 > resullt2, result = result1. otherwise, result = result2.
*/

//Global variable
int i, j, k;
string result1, result2;
string dummy1, dummy2;


void check(string a, string b);
void checkS1(string a, string b);
void checkS2(string a, string b);

int main(){
	string s1 = "AGGTAB";
	string s2 = "GXTXAYB";
	cout << s1 << " 	"<< s2 << endl;
	
	check(s1,s2);
	
	return 0;
}

void check(string a, string b){
	
	checkS1(a,b);
	checkS2(a,b);
	cout << "result1:" << result1 << ",result2: " << result2 << endl;
	if(result1.length() > result2.length()){
		cout << "result: " << result1 << endl;			
	}
	else if(result2.length() > result1.length()){
		cout << "result: " << result2 << endl;
	}
	else
		cout << "result: " << result1 << " and " << result2 << endl;

	
};

void checkS1(string a, string b){
	
	dummy1 = a;
	dummy2 = b;
	
	for (i =0; i<dummy1.length(); i++){
		for (j=0; j < dummy2.length(); j++){
			cout << "checkS1: " << dummy1[i] << dummy2[j] << " j: " << j<< endl;
			if (dummy1[i]==dummy2[j]){
				cout << "checkS1 common: " << dummy1[i] << dummy2[j] << endl; 
				result1.push_back(dummy1[i]);
				dummy2.erase(0,j+1);
				break;
			}
			
		}
		
		if(dummy2.length()==0)
			break;
		
	}
};

void checkS2(string a, string b){
	
	dummy1 = a;
	dummy2 = b;
	
	for (i =0; i<dummy2.length(); i++){
		for (j=0; j < dummy1.length(); j++){
			cout << "checkS2: " << dummy2[i] << dummy1[j] << " j: " << j<< endl;
			if (dummy2[i]==dummy1[j]){
				cout << "checkS2 common: " << dummy2[i] << dummy1[j] << endl; 
				result2.push_back(dummy2[i]);
				dummy1.erase(0,j+1);
				break;
			}
			
		}
		
		if(dummy1.length()==0)
			break;
		
	}
};