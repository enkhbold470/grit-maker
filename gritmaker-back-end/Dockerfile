FROM python:latest

LABEL Maintainer="enkhbold470"

RUN apt-get update
RUN apt-get install -yq tzdata
ENV TZ="America/Los_Angeles"


WORKDIR /gritmaker-back-end/
# Install dependencies:
COPY . /gritmaker-back-end/
RUN python3 -m pip install -r requirements.txt
RUN source venv/bin/activate
# Run the application:
# COPY main.py /app/
RUN echo "NOW IT IS STARTED"
CMD [ "python3", "/gritmaker/manage.py", "runserver"]

