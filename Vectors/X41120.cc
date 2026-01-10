#include <iostream>
#include <vector>
using namespace std;

 vector<int> obtain_peaks(const vector<int>& v){
    int n = v.size();
    vector<int> peaks;
    int point1, point2 = v[0], point3 = v[1];
    for (int i = 2; i < n; i++)
    {
        point1 = point2;
        point2 = point3;
        point3 = v[i];
        if(point2 > point1 && point2 > point3) peaks.push_back(point2);
    }
    return peaks;
 }

 int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<int> peaks = obtain_peaks(v);
    int peakCount = peaks.size();
    
    // Output all peaks
    cout << peakCount << ":";
    for (int i = 0; i < peakCount; i++) {
        cout << " " << peaks[i];
    }
    cout << endl;
    
    // Find peaks higher than the last peak
    vector<int> higherThanLast;
    if (peakCount > 0) {
        int lastPeak = peaks[peakCount - 1];
        for (int i = 0; i < peakCount - 1; i++) {
            if (peaks[i] > lastPeak) higherThanLast.push_back(peaks[i]);
        }
    }
    
    // Output peaks higher than last peak
    if (higherThanLast.empty()) cout << "-" << endl;
    else {
        for (int i = 0; i < higherThanLast.size(); i++) {
            cout << higherThanLast[i];
            if (i != higherThanLast.size() - 1) cout << " ";
        }
        cout << endl;
    }
}