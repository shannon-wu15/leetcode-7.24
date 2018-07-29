class Solution {
public:
    void recursion(vector<int> num, int i, vector<vector<int> > &res) {
		if (i == num.size()) {
			res.push_back(num);
			return;
		}
		for (int k = i; k < num.size(); k++) {
			if (i != k && num[i] == num[k]) continue;//i,k?????
			swap(num[i], num[k]);//一次
			recursion(num, i + 1, res);
		}
	}
	vector<vector<int> > permuteUnique(vector<int> &num) {
		sort(num.begin(), num.end());//
		vector<vector<int> >res;
		recursion(num, 0, res);
		return res;
	}
};