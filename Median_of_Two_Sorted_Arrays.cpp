class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int len = len1 + len2;
        if (len % 2 == 1){	//奇数
        	return getNumByIndex(nums1, nums2, len/2);
        }else{				//偶数
        	return 0.5 * (getNumByIndex(nums1, nums2, len/2 - 1) + getNumByIndex(nums1, nums2, len/2));
        }
    }

    //根据索引找两个数组排序后的值
    double getNumByIndex(vector<int>& nums1, vector<int>& nums2, int index){
    	int pos1 = 0, pos2 = 0;
        int len1 = nums1.size(), len2 = nums2.size();
        int len = len1 + len2;
        int which_one;

        for(int i = 0; i <= index;i++){
        	if (pos1 < len1 && pos2 < len2){
        		if (nums1[pos1] < nums2[pos2]){
        			pos1++;
        			which_one = 1;
        		}else{
        			pos2++;
        			which_one = 2;
        		}
        	}else if (pos1 == len1){
        		pos2++;
        		which_one = 2;
        	}else if (pos2 == len2){
        		pos1++;
        		which_one = 1;
        	}
        }

        if (which_one == 1){
        	return nums1[pos1-1];
        }else{
        	return nums2[pos2-1];
        }
    }
};