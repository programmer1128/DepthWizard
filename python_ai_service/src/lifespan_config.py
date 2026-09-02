class LifespanConfig:

    def load_model_to_gpu(self):
        pass

    def startup_event(self):
        self.load_model_to_gpu()

    def shutdown_event(self):
        pass