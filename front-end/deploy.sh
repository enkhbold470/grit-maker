#!/bin/bash

# Build the Next.js project
echo "Building Next.js project..."
npm run build

# Check if the build was successful
if [ $? -ne 0 ]; then
  echo "Error: Next.js build failed. Deployment aborted."
  exit 1
fi

# Optional: You can add additional steps here, such as running tests

# Deploy the built static files to the default Nginx directory on the server
echo "Deploying static files to Nginx default directory on server (40.112.165.245)..."
rsync -avz --delete-after ./out/ inky@40.112.165.245:/var/www/html

echo "Deployment completed successfully!"
exit 0
