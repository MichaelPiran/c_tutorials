.PHONY: staging
staging:	
	@echo "Staging all..."
	git add .

.PHONY: commit
commit: staging
	@echo "Commit all..."
	git commit --all

.PHONY: push
push: commit
	@echo "Pushing to remote repository..."
	git push
	@echo "Git workflow complete!"
