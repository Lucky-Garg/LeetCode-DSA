/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int bsA(MountainArray &arr , int s , int e , int x){
        while(s <= e){
            int mid = s + (e-s)/2;

            if(arr.get(mid) == x) return mid;

            if(arr.get(mid) > x){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return -1;
    }
    int bsD(MountainArray &arr , int s , int e , int x){
        while(s <= e){
            int mid = s + (e-s)/2;

            if(arr.get(mid) == x) return mid;

            if(arr.get(mid) > x){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return -1;
    }
     int peakIdx(MountainArray &arr) {
        int n = arr.length();

        int l = 0;
        int h = n - 1;

        while (l < h) {
            int mid = l + (h - l) / 2;

            if (arr.get(mid) < arr.get(mid + 1)) {
                l = mid + 1;
            }
            else {
                h = mid;
            }
        }

        return l;
    }
    int findInMountainArray(int x, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int idx = peakIdx(mountainArr);
        int firstPart = bsA(mountainArr , 0 ,  idx-1 , x);
        int secondPart = bsD(mountainArr , idx , n-1, x);
        if(firstPart == -1 && secondPart != -1) return secondPart;
        if(secondPart == -1 && firstPart != -1) return firstPart;

        return min(firstPart , secondPart);
    }
};