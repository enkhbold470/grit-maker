# Generated by Django 2.2.14 on 2023-12-04 03:20

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('gritmakerApp', '0001_initial'),
    ]

    operations = [
        migrations.AddField(
            model_name='sensordata',
            name='device_id',
            field=models.CharField(default='', max_length=255),
        ),
        migrations.AddField(
            model_name='sensordata',
            name='name',
            field=models.CharField(default='', max_length=255),
        ),
    ]
