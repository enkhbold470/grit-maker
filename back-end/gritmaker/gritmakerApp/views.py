# gritmakerApp/views.py
from django.http import JsonResponse
from django.views.decorators.csrf import csrf_exempt
from .models import SensorData
import json

@csrf_exempt
def sensor_data(request):
    if request.method == 'POST':
        try:
            data = json.loads(request.body)
            value = data.get('value')
            name = data.get('name')
            device_id = data.get('device_id')
            if not value:
                return JsonResponse({'status': 'error', 'message': 'Value is missing'})
            if not name or not device_id:
                return JsonResponse({'status': 'error', 'message': 'Name or device_id is missing'})

            sensor_data = SensorData(value=value, name=name, device_id=device_id)
            sensor_data.save()

            return JsonResponse({'status': 'success'})

        except json.JSONDecodeError:
            return JsonResponse({'status': 'error', 'message': 'Invalid JSON format'})

    return JsonResponse({'status': 'error', 'message': 'Invalid request method'})
