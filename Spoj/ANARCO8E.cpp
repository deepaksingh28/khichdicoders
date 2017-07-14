    #include <iostream>
    using namespace std;

    int main() {

    	// your code here
    	int a,b;
    	while(true) {
    		cin>>a>>b;
    		if(a == -1 || b == -1)
    			return 0;
    		if(a == 1 || b == 1) {
    			cout<<a<<"+"<<b<<"="<<a+b<<endl;
    		} else {
    			cout<<a<<"+"<<b<<"!="<<a+b<<endl;
    		}
    	}

    	return 0;
    }
