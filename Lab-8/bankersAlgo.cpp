#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
	int P,R;
	cout<<"Enter values of P and R : \n";
	cin >> P >> R;
    int need[P][R],processes[P],avail[R],maxm[P][R],allot[P][R],work[R],safeSeq[P],count = 0;
    bool finish[P];
    memset(finish,false,sizeof(finish));

    cout<<"Enter values of P : \n";
    for(int i=0;i<P;i++)
        cin>>processes[i];

    cout<<"Enter values of available instances : \n";
    for(int i=0;i<R;i++)
        cin>>avail[i];

    cout<<"Enter values of allocated matrix : \n";
    for(int i=0;i<P;i++) {
        for(int j=0;j<R;j++) {
            cin>>allot[i][j];
        }
    }

    cout<<"Enter values of Maximum Resource matrix : \n";
    for(int i=0;i<P;i++) {
        for(int j=0;j<R;j++) {
            cin>>maxm[i][j];
        }
    }

    for (int i = 0 ; i < P ; i++) {
		for (int j = 0 ; j < R ; j++) {
			need[i][j] = maxm[i][j] - allot[i][j];
		}
    }

	for (int i = 0; i < R ; i++) {
        work[i] = avail[i];
    }

	while (count < P)
	{
		bool found = false;
		for (int i = 0; i < P; i++)
		{
			if (finish[i] == 0)
			{
				int j;
				for (j = 0; j < R; j++) {
					if (need[i][j] > work[j]) {
						break;
					}
				}

				if (j == R) // all resources satisfied
				{
					for (int k = 0 ; k < R ; k++) {
						work[k] += allot[i][k];
					}

					safeSeq[count++] = i;
					finish[i] = 1;

					found = true;
				}
			}
		}

		if (found == false) {
			cout << "System is not in safe state";
			exit(0);
		}
	}
	cout << "System is in safe state.\nSafe sequence is: ";
	
	for (int i = 0; i < P ; i++) {
		cout << safeSeq[i] << " ";
	}

	return 0;
}

