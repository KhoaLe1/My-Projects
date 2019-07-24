     //Khoa Le
//Mass Kizar Cassiere
//CSPS 121-15
//Shuffle Sort
using namespace std;
//------------------------------------------------------------------------------
void sorting(string foo[],int bar)
  {
  clock_t begin = clock();
  sort(foo, foo + bar);
  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  cout << " Time took to sort: " << elapsed_secs << " sec.\n";
  }
//------------------------------------------------------------------------------
  void expo(string foo[], int bar)
  {
    ofstream out_file ("sorted.txt");
    clock_t begin_2= clock();
    if (out_file.is_open())
    {
      for(int j=0; j < bar; j++)
      {
        out_file << foo[j] << endl;
      }
      out_file.close();
    }
      clock_t end_2 = clock();
      double elapsed_sec2 = double(end_2 - begin_2)/ CLOCKS_PER_SEC;
      cout << " Time took to write: " << elapsed_sec2 << " sec.\n";
  }
//------------------------------------------------------------------------------
    void search(string foo[])
    {
      int i, t;
      int difference;
      clock_t begin_3 = clock();
      for( int j=0; j < 235886; j++)
      {
      if(foo[j] == "megaloblastic"){
            i = j;
          }
      if(foo[j] == "impiety"){
            t = j;
          }
      }
      clock_t end_3 = clock();
      double elapsed_sec3 = double(end_3 - begin_3)/ CLOCKS_PER_SEC;
      cout << " Time took to search for megaloblastic and impiety: "
          << elapsed_sec3 << " sec.\n";

        difference = abs(i - t);
        cout << " The words megaloblastic and impiety are "
             << difference << " lines apart.\n";
    }
