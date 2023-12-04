FROM python:latest

LABEL Maintainer="enkhbold470"

RUN apt-get update
RUN apt-get install -yq tzdata
ENV TZ="America/Los_Angeles"


WORKDIR /gritmaker-back-end/
# Install dependencies:
COPY gritmaker/ /gritmaker-back-end/
COPY requirements.txt /gritmaker-back-end/
RUN python3 -m pip install -r requirements.txt
# Run the application:
# COPY main.py /app/
RUN cd gritmaker
RUN echo "NOW IT IS STARTED"
CMD [ "python3", "./manage.py", "runserver", "0.0.0.0:8000" ]
