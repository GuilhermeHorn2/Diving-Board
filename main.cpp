#include <iostream>
#include <vector>



std::vector<int> all_lengths(std::vector<int> v,int k);
void calc_lenghts(int k,std::vector<int> &all,int len,int last);
bool int_list(std::vector<int> &all,int x);

int main()
{
	 /* ?\n;||(or) e &&(and)*/

	std::vector<int> all = all_lengths({2,3},2);
	for(int i = 0;i < all.size();i++){
		std::cout << all[i] << " ";
	}




	return 0;
}

bool in_list(std::vector<int>& all,int x){

	for(int i = 0;i < all.size();i++){
		if(all[i] == x){
			return true;
		}
	}
	return false;

}

void calc_lengths(int k,std::vector<int> v,std::vector<int> &all,int len,int last){

	//v[0] : small ; v[1] : big
	//base case k == c(k planks where used)
	if(k == 0){
		if(!in_list(all,len)){
			all.push_back(len);
		}
		len -= v[last];
		return;
	}

	//I now that the size of v is 2
	for(int i = 0;i < 2;i++){

		if(k > 0){
			calc_lengths(k-1,v,all,len+v[i],i);
		}

	}

}
std::vector<int> all_lengths(std::vector<int> v,int k){

	std::vector<int> all;
	calc_lengths(k,v,all,0,0);
	return all;
}





