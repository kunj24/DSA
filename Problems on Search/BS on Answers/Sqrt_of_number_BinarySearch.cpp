#include <iostream>
#include <vector>
using namespace std;


int sqrtofnumber(int n) {
    int ans;
    for(int i=0;i<n;i++){
        if(i*i<=n){
            ans=i;
        }
        else{
            break;
        }
    }
    return ans;
}

int main() {
    int n, target;

    cout << "Enter number of that you need to sqrt : "<<endl;
    cin >> n;

    int ans=sqrtofnumber(n);

    cout<<"The sqrt of the "<<n<<" is (floor value) : "<<ans;
    return 0;
}


