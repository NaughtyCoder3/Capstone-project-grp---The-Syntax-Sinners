#include<iostream>
using namespace std;

class Queue_Manager{
    public:
    int no_of_gates;
    int people_limit;
    float time_taken_for_one_attendee;

    /* public:
    void get_data(){
        cout<<"Enter the Number of Gates in the Stadium : ";
        cin>>no_of_gates;
        cout<<"Enter the Number of People Can Enter the Stadium : ";
        cin>>people_limit;
        cout<<"Enter the Time Taken By the One Attendee To Pass Through The Gate : ";
        cin>>time_taken_for_one_attendee;
    } */
};

class queue {
    public:
    int people;
    queue *next;

    queue(int people){
        this->people = 0;
        this->next = NULL;
    }

};

queue *front = NULL;
queue *rear = NULL;

int isEmpty(queue *front,queue *rear){
    if(front == rear && rear == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int enqueue(queue*&front,queue*&rear,int new_data){
    queue *new_node = new queue(new_data);
    new_node->next = NULL;
    if(new_node == NULL){
        cout<<"The Queue is FULL."<<endl;
    }
    else if(front == NULL){
        front = rear = new_node;
    }
    else{
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeue(queue *&front,queue *&rear){
    if(isEmpty(front,rear)){
        cout<<"There is No Element in the Queue to Dequeue."<<endl;
    }
    else{

        if(front == rear){
            front = rear = NULL;
        }
        else{
        front = front->next;
        }
    }
}

void print_list(queue *front,queue *rear){
    queue *temp = front;
    while(temp != NULL){
        cout<<temp->people<<"\t";
        temp = temp->next;
    }
}


int random_assignment(int gates,int people){
    int  counter = 0;
    queue *arr[gates];
        for(int  x=0;x<gates;x++){
        arr[x] = new queue(people);
        }
        for(int i=0;i<gates;i++){
            cout<<"Enter the Number of People at Gate "<<i+1<<" :\t";
            cin>>arr[i]->people;
            counter = counter + arr[i]->people;
            cout<<"counter :"<<counter<<"\n" ;
            if(counter == people){
                for(int j=i+1;j<gates;j++){
                    arr[j]->people = 0;
                }
                break;
            }
            else if(counter > people){
                int extra = counter - people;
                arr[i]->people = arr[i]->people - extra;
                cout << "There are only " << arr[i]->people << " people left for random assignment which are assigned to Gate " << (i + 1);
                for(int j=i+1;j<gates;j++){
                    arr[j]->people = 0;
                }
                break;
            }
        }
            if(counter < people){
                int remaining = people - counter;
                cout << "There are " << remaining << " people still left, so they are assigned to Gate " << gates << endl;
                arr[gates-1] = arr[gates-1] + remaining;
            }
    for(int i=0;i<gates;i++){
        cout<<"The Number of Peoples at Gate "<<i + 1<<" is : "<<arr[i]->people<<endl;
    }
}

void switching(int gates,int people){
    queue *arr[gates];
    for(int i=0;i<gates;i++){
        arr[i] = new queue(people);
    }
    for(int i =0;i<gates;i++){
        if(arr[i]->people < people/gates){
            int remaining;
            remaining = people/gates - arr[i]->people ;
            arr[i]->people = arr[i]->people + remaining;
        }
        else if(arr[i]->people > people/gates){
            int remaining;
            remaining = arr[i]->people - people/gates;
            arr[i]->people = arr[i]->people + remaining;
        }
        else{
            arr[i]->people = arr[i]->people ;
        }
        cout<<"The Number of Peoples at Gate "<<i + 1<<" is : "<<arr[i]->people<<endl;
    }
}

void entering_remaining_people(int gates,int people){
    queue *arr[gates];
    for(int i=0;i<gates;i++){
        arr[i] = new queue(people);
    }
    while(people != 0){
        for(int i=0;i<gates;i++){
            arr[i]->people = arr[i]->people + 1 ;
            people = people - 1;
        }
    }
    for(int i=0;i<gates;i++){
        cout<<"The Number of Peoples at Gate "<<i + 1<<" is : "<<arr[i]->people<<endl;
    }
}

int main() {
    Queue_Manager q;
   cout<<"Enter the Number of Gates in the Stadium : ";
        cin>>q.no_of_gates;
        cout<<"Enter the Number of People Can Enter the Stadium : ";
        cin>>q.people_limit;
        cout<<"Enter the Time Taken By the One Attendee To Pass Through The Gate : ";
        cin>>q.time_taken_for_one_attendee;

    queue *g;

    random_assignment(q.no_of_gates,q.people_limit/2);
    switching(q.no_of_gates,q.people_limit/2);
    entering_remaining_people(q.no_of_gates,q.people_limit);

    print_list(front,rear);

return 0;
}