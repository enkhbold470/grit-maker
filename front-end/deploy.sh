#!/bin/bash

# Build the Next.js project
echo "Building React.js project..."
npm run build

# Check if the build was successful
if [ $? -ne 0 ]; then
  echo "Error: React.js build failed. Deployment aborted."
  exit 1
fi

# Optional: You can add additional steps here, such as running tests

# Deploy the built static files to the default Nginx directory on the server
echo "Deploying static files to Nginx default directory on server (40.112.165.245)..."
scp -r build/* gritmaker@40.112.165.245:/var/www/gritmaker.com/

echo "Deployment completed successfully!"
exit 0