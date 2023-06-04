#include <stdio.h>
#include <string.h>

typedef struct seat {
  char name[100];      
  char surname[100];   
  int seat_number;     
} Seat;


typedef struct bus {
  Seat seats[5];       
  int bus_number;      
} Bus;


typedef struct bus_list {
  Bus buses[5];        
  int num_buses;       
} BusList;


void add_passenger(BusList* bus_list, char* name, char* surname) {
  int bus_number = bus_list->num_buses - 1;
  Bus* bus = &bus_list->buses[bus_number];
  for (int i = 0; i < 5; i++) {
    if (strlen(bus->seats[i].name) == 0) {
      strcpy(bus->seats[i].name, name);
      strcpy(bus->seats[i].surname, surname);
      bus->seats[i].seat_number = i;
      return;
    }
  }


  if (bus_number < 4) {
    bus_number++;
    bus_list->num_buses++;
    bus = &bus_list->buses[bus_number];
    bus->bus_number = bus_number;
    add_passenger(bus_list, name, surname);
  }
}

void print_buses(BusList* bus_list) {
  for (int i = 0; i < bus_list->num_buses; i++) {
    Bus* bus = &bus_list->buses[i];
    printf("Bus %d:\n", bus->bus_number);
    for (int j = 0; j < 5; j++) {
      Seat* seat = &bus->seats[j];
      if (strlen(seat->name) > 0) {
        printf("  Seat %d: %s %s\n", seat->seat_number, seat->name, seat->surname);
      }
    }
  }
}

int main() {
  BusList bus_list;
  memset(&bus_list, 0, sizeof(bus_list));
  bus_list.num_buses = 1;

  //BUS 1
  add_passenger(&bus_list, "Furkan", "TOP");
  add_passenger(&bus_list, "Şevki", "ÜNAL");
  add_passenger(&bus_list, "Utku", "ÖNDERÖZ");
  add_passenger(&bus_list, "Alperen", "AKSAR");
  add_passenger(&bus_list, "Beyza", "NUR");
 //BUS 2
  add_passenger(&bus_list, "Haris", "EREN");
  add_passenger(&bus_list, "Vildan", "ÖKTEN");
  add_passenger(&bus_list, "Faruk", "ERATA");
  add_passenger(&bus_list, "Emre", "ERASLAN");
  add_passenger(&bus_list, "Meltem", "ALBAYRAK");
  //BUS 3
  add_passenger(&bus_list, "Özlem", "ÜNAL");
  add_passenger(&bus_list, "Sonay", "KARATAŞ");
  add_passenger(&bus_list, "Berdan", "KAAN");
  add_passenger(&bus_list, "Ali", "KAHYA");
  add_passenger(&bus_list, "Dilara", "AYDIN");
  //BUS 4
  add_passenger(&bus_list, "Sümayya", "BALLI");
  add_passenger(&bus_list, "Mustafa", "YALÇIN");
  add_passenger(&bus_list, "Merve", "YILDIRIM");
  add_passenger(&bus_list, "Yağmur", "BALBOL");
  add_passenger(&bus_list, "Fatih", "DOYGUN");
  //BUS 5
  add_passenger(&bus_list, "ZÜMRAL", "DOYGUN");
  add_passenger(&bus_list, "Ruken", "EKMEN");
  add_passenger(&bus_list, "Volkan", "DOĞRU");
  add_passenger(&bus_list, "Helin", "EREN");
  add_passenger(&bus_list, "Kevser", "IKİZ");
  

  print_buses(&bus_list);

  return 0;
}