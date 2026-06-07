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
    int findPeak(MountainArray &mountainArr){
        int l = 0;
        int h = mountainArr.length() - 1;

        while(l < h){
            int mid = l + (h - l) / 2;

            if(mountainArr.get(mid) < mountainArr.get(mid + 1))
                l = mid + 1;
            else
                h = mid;
        }

        return l;
    }

    int binarySearchAsc(MountainArray &mountainArr,
                        int target,
                        int l,
                        int h){

        while(l <= h){
            int mid = l + (h - l) / 2;

            int val = mountainArr.get(mid);

            if(val == target) return mid;

            if(val < target)
                l = mid + 1;
            else
                h = mid - 1;
        }

        return -1;
    }

    int binarySearchDesc(MountainArray &mountainArr,
                         int target,
                         int l,
                         int h){

        while(l <= h){
            int mid = l + (h - l) / 2;

            int val = mountainArr.get(mid);

            if(val == target) return mid;

            if(val < target)
                h = mid - 1;
            else
                l = mid + 1;
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {

        int peak = findPeak(mountainArr);

        int left = binarySearchAsc(mountainArr,
                                   target,
                                   0,
                                   peak);

        if(left != -1)
            return left;

        return binarySearchDesc(mountainArr,
                                target,
                                peak + 1,
                                mountainArr.length() - 1);
    }
};