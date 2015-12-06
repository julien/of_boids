#include "ofApp.h"

void ofApp::setup() {
    ofBackground(0);

    unsigned int i;

    Target* target = new Target(ofGetWidth() / 2, ofGetHeight() / 2, 100, 300);
    targets.push_back(target);

    for (i = 0; i < maxEntities; ++i) {
        Particle* p = new Particle(ofGetWidth() / 2, ofGetHeight() / 2);
        particles.push_back(p);
    }
}

void ofApp::update() {

    Target* t = targets.at(0);
    t->update();

    ofVec2f pos = t->position();

    unsigned int i;
    for (i = 0; i < particles.size(); i++) {
        Particle* p = particles.at(i);
        if (p && p->alive()) {
            p->arrive(pos);

            float dist = p->position().distance(pos);

            if (dist < t->size) {
                t->hit();
            }

            if (t->dead()) {
                // targets.erase(targets.begin() + 0);
                // t = new Target(ofGetWidth() / 2, ofGetHeight() / 2, 100, 400);
                // targets.push_back(t);

                t->reset();
            }


            p->update();

            if (!p->alive()) {
                particles.erase(particles.begin() + i);
                particles.push_back(new Particle(ofGetWidth() / 2, ofGetHeight() / 2));
            }
        }
    }
}

void ofApp::draw() {
    if (showTarget) targets.at(0)->draw();

    for (unsigned int i = 0; i < particles.size(); ++i) {
        particles.at(i)->draw();
    }
}

void ofApp::keyPressed(int key)                     {  }
void ofApp::keyReleased(int key)                    {  }
void ofApp::mouseMoved(int x, int y )               {  }
void ofApp::mouseDragged(int x, int y, int button)  {  }

void ofApp::mousePressed(int x, int y, int button)  {
    showTarget = !showTarget;
}

void ofApp::mouseReleased(int x, int y, int button) {  }
void ofApp::mouseEntered(int x, int y)              {  }
void ofApp::mouseExited(int x, int y)               {  }
void ofApp::windowResized(int w, int h)             {  }
void ofApp::gotMessage(ofMessage msg)               {  }
void ofApp::dragEvent(ofDragInfo dragInfo)          {  }

