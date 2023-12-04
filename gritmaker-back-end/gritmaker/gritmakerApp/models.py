from django.db import models

# Create your models here.
from django.db import models

class SensorData(models.Model):
    value = models.FloatField()
    timestamp = models.DateTimeField(auto_now_add=True)
    name = models.CharField(max_length=255, default='')
    device_id = models.CharField(max_length=255, default='')
