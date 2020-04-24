#include "GenQueue.cpp"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

int main(int argc, char **argv){
  fstream f;
  int lines = 0;
  string path;
  char ch;
  int windows;
  int numbers;
  string line;
  int time;
  int curr_inx;
  int students;
  int numberAdded = 0;
  int t_count = 0;
  int s_count = 0;
  int n_count = 0;
  int time_0 = 0;
  int time_spent = 0;
  int wind_it = 0;
  int j=0;
  int popper = 0;
  int transfer = 0;
  int store_last = 0;
  int student_tracker = 0;
  int windowQ = 0;
  int lineAdder = 0;
  int adder = 0;
  int theSize = 0;
  float addMe = 0;
  int meanPeek = 0;
  float mean = 0;
  int longWait = 0;
  int peekMe= 0;
  int time_1 = 0;
  int time_2 = 0;
  int time_3 = 0;
  int divide = 0;
  float median = 0;
  int divide_1 = 0;
  float median_1 = 0;
  float median_2 = 0;
  int studpeek = 0;
  int studSize =0;
  int lowpeek = 0;
  int overTen = 0;
  int lowSize = 0;
  int windowLoop = 0;
  float windSize= 0;
  int windPeek = 0;
  float WindaddMe = 0;
  float Windmean =0;
  int windcounter = 0;
  int longestIdle = 0;
  int swind = 0;
  int windtoAdd=0;
  int windypeek = 0;
  int bigNum = 0;

  GenQueue<int> *wQ = new GenQueue<int>();
  GenQueue<int> *tQ = new GenQueue<int>();
  GenQueue<int> *trackTQ = new GenQueue<int>();
  GenQueue<int> *studLine = new GenQueue<int>();
  GenQueue<int> *meanWait = new GenQueue<int>();
  GenQueue<int> *medianWait =  new GenQueue<int>();
  GenQueue<int> *pp =  new GenQueue<int>();
  GenQueue<int> *low =  new GenQueue<int>();
  GenQueue<int> *idle =  new GenQueue<int>();
  GenQueue<int> *waitTime = new GenQueue<int>();

//getting the file path
  cout << "\nPlease specify the file you would like to analyze" << endl;
  cout << "Be sure it is in the same directory" << endl;
  cin>> path;

  cout << "This is the path you entered: "<< path << endl;

  fstream fin(path, fstream::in);


//count the amount of lines
  while (fin >> noskipws >> ch){
    //getting the amount of lines so I can identify where the error is
      if (ch == '\n' ){
        lines += 1;
      }
  }
  fin.close();
  fstream poo(path, fstream::in);
  int i = 0;

  //while there are lines being read run the code
  while (std::getline(poo, line)){
    // cout <<line<< endl;

    i++;

  	std::istringstream(line) >> numbers;

//getting the amount of windows

    if (i== 1){
      windows = numbers;
      // ++i;
      continue;
    }

    //iterating through the time piece of the txt file
    if ( t_count == n_count){

      store_last = time;
      t_count ++;
      time = numbers;
      // cout << "The time is:  "<<time << endl;




      time_spent = time - store_last;


//code to configure when windows are idle
      if (wQ->getSize() < windows){

        // cout << "printing the Window Idle Queue at time: "<< time<< endl;

        windowLoop = windows - wQ->getSize();

        // cout << "THE AMOUNT OF WINDOWS OPEN ARE: "<< windowLoop<< endl;

//adding for only when windows were idle to start, not when the open back up
        if (idle->getSize()>0){
          for (int v = 1; v<= windowLoop; ++v){
            idle->removeQueue();
          }
        }
        for (int v = 1; v<= windowLoop; ++v){
          idle->insertQueue(time);
        }
        // cout << "here is the windows that are idle and their time" <<endl;
        // idle->printQueue();
      }

//editting the students wait times based on how much time has gone by
      if (time_spent >0){

        // HERE IS THE QUEUE BEFORE THE TRANSFER NUMBERS HAVE BEEN ADDED
        student_tracker = wQ->getSize();
        // cout<<  wQ->getSize() <<endl;
        for (int c = 1; c<= student_tracker; ++c){
          transfer = wQ->peek();
          wQ->removeQueue();
          transfer = transfer - time_spent;
//adding in the editted numbers
          if (transfer > 0){
            wQ->insertQueue(transfer);
            //if a student completes their session
          }else {
            // cout << "One of the students has completed their session. (went to 0)"<< endl;
          }
        }
      }
      continue;
    }
    //dealing with the amount of students who just arrived
    if ( t_count>s_count){
      s_count++;
      students = numbers;
      popper+= students;
      // cout << "Students who just arrived  "<<students << endl;
      curr_inx = i;
      if (students>0){
        continue;
      }
    }
//dealing with the wait times of the amount of students who came
    if (s_count>=n_count){

      // if there are students in the line but not a full amount of windows occupied
      if (studLine->getSize()>0 && wQ->getSize()<windows){
        time_2 = time;
        time_3 = time_2- time_1;
        windowQ = wQ->getSize();
        lineAdder = windows-windowQ;

        // cout << "here is the line before we add from the line at time: "<< time<< endl;
        // studLine->printQueue();
        //adding the students into the windows + how long they waited in line
        for (int c = 1; c<= lineAdder; ++c){
          adder = studLine->peek();
          studLine->removeQueue();
          wQ->insertQueue(adder);
          if (adder>0){
            // if (adder+time_3> longWait){
            //   longWait = adder+time_3;
            // }
            meanWait->insertQueue(adder+time_3);
            pp->insertQueue(adder+time_3);
            low->insertQueue(adder+time_3);
            waitTime->insertQueue(time_3);

          }
        }
        // cout << "here is the window line after we add from the line at time: "<< time<< endl;
        // wQ->printQueue();
      }
// dealing with what happens when all the windows arent occupied
      if (wQ->getSize() < windows){

        // getting each student time inserted
        if (j<students){

          wQ->insertQueue(numbers);
// getting the longest wait time
          if (numbers!=0){
            // if (numbers> longWait){
            //   longWait = numbers;
            // }
            meanWait->insertQueue(numbers);
            pp->insertQueue(numbers);
            low->insertQueue(numbers);
          }
          // cout << "window line when windows arent full "<< time<< endl;
          // wQ->printQueue();

          j++;
          if (j<students){
            continue;
          }
        }
// if all windows are occupied inserting into the line
      } else if (wQ->getSize()==windows) {
        time_1 = time;
        studLine-> insertQueue(numbers);

        j++;
        if (j<students){
          continue;
        }
        // cout << "the line when windows are full "<< time<< endl;
        // studLine->printQueue();

        // cout << "window line when windows are full "<< time<< endl;
        // wQ->printQueue();
//if all students were taken care of
      }else if (wQ->getSize()==0 && studLine->getSize()==0){
        cout << "All of the students have been taken care of"<< endl;
      }
    }
    n_count++;
    j=0;

  }

  //final portion of code

cout <<"\nPRINTING THE FINAL WINDOW QUEUE (IF THERE IS ONE) "<<endl;

wQ->printQueue();

cout <<"\nPRINTING THE FINAL LINE QUEUE (IF THERE IS ONE)"<<endl;

studLine->printQueue();

cout <<"\nPRINTING THE WAIT TIMES FOR THE STUDENTS"<<endl;

waitTime->printQueue();

//doing insertions from the line (if there is left over ppl in line) to the queues so i can find means and other metrics
if (studLine->getSize()>0){
  studSize = studLine->getSize();

  for (int b = 1; b<= studSize; ++b){
    studpeek= studLine->peek();
    studLine->removeQueue();
    meanWait->insertQueue(studpeek);
    pp->insertQueue(studpeek);
    low->insertQueue(studpeek);
  }
}

//finding the metrics for people who waited more than 10 mins and the longest wait time
lowSize = low->getSize();
for (int b = 1; b<= lowSize; ++b){
  lowpeek = low->peek();
  // cout << "Printing lowpeek: "<< lowpeek <<endl;
  low->removeQueue();
  // if (lowpeek > 10){
  //   ++overTen;
  // }
  // if (lowpeek>longWait){
  //   longWait = lowpeek;
  // }
}

// mean wait time calculation
theSize = waitTime->getSize();
for (int x = 1; x <= theSize ; x++){
  meanPeek = waitTime->peek();
  meanWait->removeQueue();
  addMe += meanPeek;
  if (meanPeek>longWait){
    longWait=meanPeek;
  }if(meanPeek>10){
    ++overTen;
  }
}
// cout << "meanpeak: "<< meanPeek<< endl;
mean = addMe/theSize;


// calculating the window idle metrics
if (wQ->getSize()>0){
  swind = wQ->getSize();
  windtoAdd =windows-swind;
  for (int x = 1; x<= swind;++x){
    windypeek = wQ->peek();
    wQ->removeQueue();
    if (windypeek>bigNum){
      bigNum = windypeek;
    }
    wQ->insertQueue(windypeek);
  }
  for (int x = 1; x<= windtoAdd;++x){
    idle->removeQueue();
    idle->insertQueue(bigNum);
  }
// cout << "here is the window idle queue"<<endl;
//   idle->printQueue();

}


windSize = idle->getSize();
for (int x = 1; x <= windSize ; x++){
  windPeek = idle->peek();
  //longest window
  if (windPeek>longestIdle){
    longestIdle = windPeek;
  }//windows idle over 5 mins
  if (windPeek> 5){
    windcounter++;
  }
  idle->removeQueue();
  WindaddMe += windPeek;
}
//idle mean
Windmean = WindaddMe/windSize;

// code for the median, putting it in the array first and sorting it
int array [theSize];
for (int z = 0; z< theSize ; ++z){
  peekMe= waitTime->peek();
  pp->removeQueue();
  array[z] = peekMe;
}
cout << " "<< endl;

int n = sizeof(array)/sizeof(array[0]);

sort(array, array+n);

//if it is divisble by 2
if (theSize % 2 == 0){
  divide = theSize/2;
  divide_1 = divide-1;
  median_1= array[divide];
  median_2 = array[divide_1];
  median = (median_1+median_2)/2;
//if it not divisible by 2
}else{
  divide = theSize/2;
  cout << divide << endl;
  median = array[divide];
}


//printing the metics to standard output
cout << "The mean wait time is: "<< mean << endl;
cout << "The median wait time is: "<< median << endl;
cout << "The longest student wait time is: "<< longWait<< endl;
cout << "The amount of students waiting over 10 minutes is: "<< overTen<< endl;
cout << "The mean window idle time is: "<< Windmean<< endl;
cout << "The longest window idle time is: "<< longestIdle<< endl;
cout << "The amount of windows idle for more than 5 minutes is: "<< windcounter<< endl;
cout << " " << endl;

}
