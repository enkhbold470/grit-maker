from django.urls import path
from .views import sensor_data

urlpatterns = [
    path('sensor_data/', sensor_data, name='sensor_data'),
]
