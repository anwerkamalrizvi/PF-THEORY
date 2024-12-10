/*
In a cutting-edge agritech system for precision farming, a dynamic pointer-based architecture is
.................................................................................................
structures, the agritech platform offers farmers a futuristic, data-driven farming experience that
maximizes yield, minimizes waste, and supports sustainable agricultural practices.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *crop_type;
    char *growth_stage;
    float expected_yield;
} Crop;

typedef struct {
        float temperature;
    float rainfall;
    float wind_speed;

} WeatherForecast;

typedef struct {
    char *equipment_name;
    char *status;
    float fuel_level;
    char *activity_schedule;


} Equipment;
 
typedef struct {
     float soil_nutrients;
    float soil_ph;
    int pest_activity;
} Sensor;

typedef struct Field {
    float latitude;
    float longitude;
    float soil_health;
    float moisture_level;
    Crop **crops;
    WeatherForecast *weather;
    Equipment **equipment;
  
    Sensor **sensors;
  
    int num_crops;
    int num_equipment;
    int num_sensors;
} Field;

typedef struct {
    Field **fields;
    int num_fields;
} RegionalHub;

Crop* create_crop(char *crop_type, char *growth_stage, float expected_yield)
{
  
    Crop *new_crop = (Crop*)malloc(sizeof(Crop));
    new_crop->crop_type = crop_type;
  
  
    new_crop->growth_stage = growth_stage;
    new_crop->expected_yield = expected_yield;
    return new_crop;
}

WeatherForecast* create_weather_forecast(float temperature, float rainfall, float wind_speed)
{
  
    WeatherForecast *new_weather = (WeatherForecast*)malloc(sizeof(WeatherForecast));
  
    new_weather->temperature = temperature;
    new_weather->rainfall = rainfall;
    new_weather->wind_speed = wind_speed;
  
    return new_weather;
}

Equipment* create_equipment(char *equipment_name, char *status, float fuel_level, char *activity_schedule)
{
    Equipment *new_equipment = (Equipment*)malloc(sizeof(Equipment));
  
  
    new_equipment->equipment_name = equipment_name;
    new_equipment->status = status;
    new_equipment->fuel_level = fuel_level;
    new_equipment->activity_schedule = activity_schedule;
    return new_equipment;
}

Sensor* create_sensor(float soil_nutrients, float soil_ph, int pest_activity)
{
    Sensor *new_sensor = (Sensor*)malloc(sizeof(Sensor));
       new_sensor->soil_nutrients = soil_nutrients;
    new_sensor->soil_ph = soil_ph;
    new_sensor->pest_activity = pest_activity;
    return new_sensor;
}

Field* create_field(float latitude, float longitude, float soil_health, float moisture_level, int num_crops, int num_equipment, int num_sensors)
{
    Field *new_field = (Field*)malloc(sizeof(Field));
    new_field ->latitude = latitude;
    new_field->longitude = longitude;
    new_field->soil_health = soil_health;
    new_field->  moisture_level = moisture_level;
    new_field-> num_crops = num_crops;
    new_field->num_equipment = num_equipment;
    new_field-> num_sensors = num_sensors;
    new_field->crops = (Crop**)malloc(num_crops *sizeof(Crop*));
    new_field ->equipment = (Equipment**)malloc(num_equipment*sizeof(Equipment*));
    new_field-> sensors = (Sensor**) malloc(num_sensors*sizeof(Sensor*));
    return new_field;
}

RegionalHub* create_regional_hub(int num_fields)
{
    RegionalHub *new_hub = (RegionalHub*)malloc (sizeof(RegionalHub));
    new_hub->num_fields = num_fields;
    new_hub->fields = (Field**)malloc (num_fields*sizeof(Field*));
    
    return new_hub;

}

void print_field_info(Field *field)
{

    printf("Field Location: Latitude %.2f, Longitude %.2f\n", field->latitude, field->longitude);   printf("Soil Health: %.2f, Moisture Level: %.2f\n", field->soil_health, field->moisture_level);

    printf("Crops:\n");
    for(int i = 0; i < field->num_crops; i++)
    {
   
        printf("  - Crop Type: %s, Growth Stage: %s, Expected Yield: %.2f\n", field->crops[i]->crop_type, field->crops[i]->growth_stage, field->crops[i]->expected_yield);
     }

    
    printf("Weather Forecast: Temperature %.2fDegree Celcis, Rainfall %.2fmm, Wind Speed %.2fm/s\n", field->weather->temperature, field->weather->rainfall, field->weather->wind_speed);

    
    printf("Sensors:\n");
        for(int i = 0; i < field->num_sensors; i++)

    
    {
         printf("  - Soil Nutrients: %.2f, Soil pH: %.2f, Pest Activity: %d\n", field->sensors[i]->soil_nutrients, field->sensors[i]->soil_ph, field->sensors[i]->pest_activity);
    }
}

int main()
{
    
    Crop *wheat = create_crop("Wheat", "Vegetative", 3.5);
     
     Crop *corn = create_crop("Corn", "Reproductive", 4.2);

    WeatherForecast *forecast = create_weather_forecast(25.5, 10.2, 3.0);

    
    Sensor *sensor1 = create_sensor(1.2, 6.5, 3);
    
    Sensor *sensor2 = create_sensor(1.4, 6.8, 2);

    Field *field = create_field(34.0522, -118.2437, 85.0, 40.0, 2, 0, 2);
    field->crops[0] = wheat;
    
    field-> crops[1] = corn;
    field ->weather = forecast;
    field->sensors[0] = sensor1;
        field-> sensors[1] = sensor2;

    print_field_info(field);

    free(wheat);

    free(corn);
    free(forecast);
    free(sensor1);
    free(sensor2);
    
    free(field -> crops);
    free(field -> sensors);
    free(field);

    return 0;
}
