#!/bin/bash
REPO_NAME=$(basename `git rev-parse --show-toplevel`)
BRANCH_NAME=$(git rev-parse --abbrev-ref HEAD)
LAST_COMMIT=$(git rev-parse --short HEAD)
BUNDLE_FILENAME=${REPO_NAME}_${BRANCH_NAME}_$(date +%m-%d-%Y)_${LAST_COMMIT}.bundle

echo "Making bundle ${BUNDLE_FILENAME} from branch ${BRANCH_NAME}"
git bundle create ${BUNDLE_FILENAME} ${BRANCH_NAME} --branches --tags
echo "...done."