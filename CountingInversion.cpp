long countInversions(vector<int> arr) {
  int count = 0;
    for(int i= 0;i<arr.size();i++)
    {
      for(int j = i+1;j<arr.size();j++)
      {
        if(arr[i]>arr[j])
        {
          count++;
        }
      }
    }
    return count;
}
